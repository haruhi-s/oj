module RegExpParser
       ( RegExp(..)
       , parseRegExp
       ) where
import Text.ParserCombinators.ReadP
import Control.Arrow ((>>>))

data RegExp = Normal Char       -- ^ A character that is not in "()*|."
            | Any               -- ^ Any charater
            | ZeroOrMore RegExp -- ^ Zero or more occurances of the same regexp
            | Or RegExp RegExp  -- ^ A choice between 2 regexps
            | Str [RegExp]      -- ^ A sequence of regexps.
  deriving (Show, Eq)


ch = satisfy$(`elem` "()*|")>>>not

normal_ = do
  a<-ch
  return $Normal a
any_ = do
  char '.'
  return Any
str = do
  t<-many1 $stre
  return $if tail t == []
          then head t
          else Str t
stre = reg+++zom

e = str+++or_
bra = do
  char '('
  x<-e
  char ')'
  return x
zom = do
  a <- reg
  char '*'
  return $ ZeroOrMore a
-- or_ = chainr1 (reg+++str+++zom) (char '|'>>return(\a b -> if a == b
--                                                           then a
--                                                           else Or a b))
or_ = do
  a <- str
  char '|'
  b <- str
  return (Or a b)

reg = normal_ +++ any_ +++ bra

foo = readP_to_S e
bar [] = Nothing
bar xs = Just $fst.last$xs
baz = filter ((=="").snd)
parseRegExp :: String -> Maybe RegExp
parseRegExp = bar.baz.foo
