module ApplicativeParser where

import Control.Arrow
import Control.Monad
import Data.Char
import Prelude hiding (fmap)

-- | An ambiguous parser.
newtype Parser a = P { unP :: String -> [(String, a)] }

liftA2 f a b = f <#> a <@> b

-- | Change the result of a parser.
pmap :: (a -> b) -> Parser a -> Parser b
pmap f p = P $ (unP p) >>> (second f <$>)

-- | Operator version of 'pmap'.
(<#>) :: (a -> b) -> Parser a -> Parser b
(<#>) = pmap

-- | Parse a value and replace it.
(<#) :: a -> Parser b -> Parser a
(<#) = pmap . const

infixl 4 <#>
infixl 4 <#

-- | Parse a character only when a predicate matches.
predP :: (Char -> Bool) -> Parser Char
predP p = P $ \xs' -> case xs' of
                        (x:xs) -> if p x
                                  then [(xs,x)]
                                  else []
                        _ -> []

-- | Succeed only when parsing the given character.
charP :: Char -> Parser Char
charP = predP . (==)

-- | Inject a value into an identity parser.
inject :: a -> Parser a
inject x = P $ \s -> [(s,x)]

-- | Given a parser with a function value and another parser, parse the function
-- first and then the value, return a parser which applies the function to the
-- value.
(<@>) :: Parser (a -> b) -> Parser a -> Parser b
pf <@> px = P $ \s -> [second fs xs| (ss,fs) <- unP pf s, xs <- unP px ss]

(<@) :: Parser a -> Parser b -> Parser a
pa <@ pb = P((second const <$>) . unP pa) <@> pb

(@>) :: Parser a -> Parser b -> Parser b
pa @> pb = P((second (const id) <$>) . unP pa) <@> pb

infixl 4 <@
infixl 4 @>
infixl 4 <@>

-- | Parse a whole string.
stringP :: [Char] -> Parser [Char]
stringP = foldr (liftA2 (:)) (inject "") . (charP <$>)

-- | Construct a parser that never parses anything.
emptyP :: Parser a
emptyP = P $ const []

-- | Combine two parsers: When given an input, provide the results of both parser run on the input.
(<<>>) :: Parser a -> Parser a -> Parser a
pa <<>> pb = P $ \s -> unP pa s ++ unP pb s

infixl 3 <<>>
(<|>) = (<<>>)
-- | Apply the parser zero or more times.
many :: Parser a -> Parser [a]
many v = mv
  where mv = sv <|> inject []
        sv = liftA2 (:) v mv
some :: Parser a -> Parser [a]
some v = sv
  where mv = sv <|> inject []
        sv = liftA2 (:) v mv


-- | Apply a parser and return all ambiguous results, but only those where the input was fully consumed.
runParser :: Parser a -> String -> [a]
runParser p = map snd . filter ((=="").fst) . unP p

-- | Apply a parser and only return a result, if there was only one unambiguous result with output fully consumed.
runParserUnique :: Parser a -> String -> Maybe a
runParserUnique p cs = case runParser p cs of
                         [a] -> Just a
                         _   -> Nothing

-- | Kinds of binary operators.
data BinOp = AddBO | MulBO deriving (Eq, Show)

-- | Some kind of arithmetic expression.
data Expr = ConstE Int
          | BinOpE BinOp Expr Expr
          | NegE Expr
          | ZeroE
          deriving (Eq, Show)

evalExpr :: Expr -> Int
evalExpr a = case a of
  ConstE a -> a
  BinOpE AddBO a b -> evalExpr a + evalExpr b
  BinOpE MulBO a b -> evalExpr a * evalExpr b
  NegE a -> -evalExpr a
  ZeroE -> 0

-- | Parse arithmetic expressions, with the following grammar:
--
expr :: Parser Expr
expr = cons <|> binOpExpr <|> neg <|> zero
cons :: Parser Expr
cons = ConstE . read <#> some (predP $ (`elem` ['0'..'9']))
binOpExpr =
  charP '(' @>
  ((\e _ b _ f -> BinOpE b e f) <#>
  expr <@> (charP ' ') <@> binOp <@> (charP ' ') <@> expr)
  <@ charP ')'

binOp = const AddBO <#> charP '+' <<>> const MulBO <#> charP '*'
neg   = liftA2 (const NegE) (charP '-') expr
zero  = const ZeroE <#> charP 'z'
--
parseExpr :: String -> Maybe Expr
parseExpr = runParserUnique expr

