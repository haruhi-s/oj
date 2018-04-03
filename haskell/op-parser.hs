{-# LANGUAGE DeriveFunctor #-}

module OperatorParser
    ( OpTree(..)
    , Associativity(..)
    , op
    , foldTree
    , parseOperators
    , module Text.ParserCombinators.ReadP
    )
where

import Text.ParserCombinators.ReadP
import Control.Applicative hiding (many)
import Data.Char
-- | Type for operator parse results. 'a' is the type of the operator, 'b'
-- | of the terms.
data OpTree a b = Op (OpTree a b) a (OpTree a b)
                | Term b
                deriving (Show, Eq, Functor)

-- | Type for specifying the assocativity of operators: left, right, or none.
data Associativity a = L a | R a | NoAssociativity a
                     deriving (Show, Eq, Functor)

-- | Transform an OpTree using the given function.
foldTree :: (a -> b -> b -> b) -> OpTree a b -> b
foldTree _ (Term b) = b
foldTree f (Op x a y) = f a (foldTree f x) (foldTree f y)

-- | Return a parser such that: given 'op s a', if s matches, the parser
-- | returns a.
op :: String -> a -> ReadP a
op s a = do string s
            return a
spaces = many (choice (map char " \n"))
-- | Accept two arguments:
-- | (1) A list of type [Associativity [ReadP a]], which contains parsers for
-- | operators (ReadP a). Each item of type Associativity [ReadP a] contains
-- | a group of operator parsers of the same precedence and associativity;
-- | these groups are listed in order of precedence (lowest to highest).
-- | (2) A parser for the terms.
-- | And return a parser for operator expressions that yields a parse tree.
parseOperators :: [Associativity [ReadP a]] -> ReadP b -> ReadP (OpTree a b)
parseOperators xss t = do
  pO xss t br
    where br = do char '('
                  spaces
                  a <- parseOperators xss t
                  spaces
                  char ')'
                  return a
pO [] t br = br+++do
  x <- t
  return $Term x
pO ((oops):xss) t br =
  (+++) br$
  (case baz of
     0 -> chainr1
     1 -> chainl1
     2 -> \a b -> a +++ do{
       x <- a;
       z <- b;
       y <- a;
       return $z x y
                          }
  )
  (pO xss t br) $ foldr1 (+++) $map quu ops
  where ops = foo oops
        foo (L x) = x
        foo (R x) = x
        foo (NoAssociativity x) = x
        baz = bar oops
        bar (R x) = 0
        bar (L x) = 1
        bar (NoAssociativity x) = 2
        quu = (\a -> do{
                  spaces;
                  a'<-a;
                  spaces;
                  return (\p q -> Op p a' q)})








arithOps :: [Associativity [ReadP String]]
arithOps =
    map (fmap (map (\s -> op s s) . words))
        [ R "&& ||", NoAssociativity "< > =", L "+ -", L "* /", R "^"]

arithParser :: String -> String
arithParser s =
    case readP_to_S (parseOperators arithOps (munch1 isDigit) <* eof) s of
        [] -> ""
        xs -> brackets $ fst (last xs)

brackets :: OpTree String String -> String
brackets = foldTree (\o x y -> '(' : x ++ o ++ y ++ ")")

parsesTo :: Eq a => (a, String) -> [(a, String)] -> Bool
parsesTo _ [] = False
parsesTo x xs = last xs == x

exampleTree :: OpTree String String
exampleTree =
    Op (Op (Term "1") "*" (Term "2"))
       "+"
       (Op (Term "3") "/" (Op (Term "5") "^" (Term "6")))
