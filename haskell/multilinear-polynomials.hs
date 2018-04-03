import Data.List
import Text.ParserCombinators.ReadP

data P a =
  Elem [Char]
  |Mul (P a) Int
  |Op (P a) Char
  |Branch (P a) (P a)
   deriving (Show, Eq)

unit = ele +++ mult
ele = do s <- (+++) (string "") $ many1 (choice (map char ['a'..'z']))
         return (Elem (sort s))

mult = do e <- ele
          d <- digit
          return (Mul e d)

digit = do s <- many1 (choice (map char ['0'..'9']))
           return (read (reverse s)::Int)

op = do a <- ele +++ mult
        o <- (choice (map char ['+','-']))
        return (Op a o)

branch = do a <- ele +++ mult +++ op
            char ' '
            b <- fina
            return (Branch a b)
fina = ele +++ op +++ mult +++ branch

r s = fst$ last $ readP_to_S fina (reverse (sp'$sp s))

-- (+-+) :: [(String,Int)] -> [(String,Int)] -> [(String,Int)]
(+-+) [] a = a
(+-+) a [] = a
(+-+) (x:xs) a = xs +-+ ins x a
  where ins x [] = [x]
        ins x@(s,n) (a@(s',n'):as) = if s == s'
                                     then (s,n+n'):as
                                     else a:(ins x as)
-- (***) :: Int -> [(String,Int)] -> [(String,Int)]
(***) x = map (\(s,n) -> (s,n*x))
eval :: P a -> [([Char],Int)]
eval (Elem a) = [(a,1)]
eval (Mul a n) = n *** (eval a)
eval (Op a '+') = eval a
eval (Op a '-') = (-1) *** eval a
eval (Branch a b) = (eval a) +-+ (eval b)

sp "" = ""
sp (a:xs) = if a == '+' || a == '-'
            then ' ':a:(sp xs)
            else a:(sp xs)
sp' (' ':s) = s
sp' s = s

re s = map (\(a,b,c) -> (b,c)) $sort $ map (\(a,b) -> (length a,a,b)) (eval $ r s)

rep [] = ""
rep (x@(a,b):xs) =
    case b of
      0 -> rep xs
      1 -> ('+':a)++(rep xs)
      -1 -> ('-':a)++(rep xs)
      otherwise -> if b > 0
                   then ('+':(show b)++a)++(rep xs)
                   else (show b)++a++(rep xs)

fc ('+':s) = s
fc s = s

simplify = fc . rep . re
