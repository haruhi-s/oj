import Text.ParserCombinators.ReadP
import Control.Monad hiding (ap)
s x y z = x z (y z)
k = const
i = id

-- Types for Lambda Calculus and SKI combinators
type V = String
data L = Va V
       | Ap L L
       | Ab V L
       | S | K | I
       deriving (Show,Eq)
sho (Va a) = a
sho (Ap x y) = "("++sho x++" "++sho y++")"
sho (Ab a x) = "("++"\\"++a++"."++sho x++")"
sho S = "S"
sho K = "K"
sho I = "I"

-- Interpreter
r = fst.last.(readP_to_S ll)
spaces = many1(char ' ')
sp = many(char ' ')
word = many1.satisfy $ flip elem ['a'..'z']
va = word >>= (return.Va)       -- Variables
ap = do spaces                  -- Applying expressions
        return Ap
ab = do a <- word               -- Abstraction as (x.E), meaning
        sp                      -- \x->E
        char '.'
        sp
        b <- ll
        return $ Ab a b

co = do
  a <- satisfy . (flip elem) $ "SKI"
  return (f a)                  -- Combinators S,K and I
  where f a = case a of
                'S' -> S
                'K' -> K
                'I' -> I
br = do char '('                -- Brackets
        sp
        a <- ll
        sp
        char ')'
        return a
at = br +++ co +++ va           -- Atoms(indivisible)
ll :: ReadP L                   -- Final expressions
ll = choice [chainl1 at ap,ab,at]

t (Va a) = (Va a)               -- Translator
t S = S
t K = K
t I = I
t (Ap x y) = Ap (t x) (t y)
t (Ab a (Va b)) = if a == b
                  then I
                  else (Ap K (Va b))
t (Ab a (Ap x y)) = Ap (Ap S (t$Ab a x)) (t$Ab a y)
t (Ab a (Ab b x)) = t (Ab a $ t (Ab b x))
t (Ab a b) = Ap K b
st = show.t

main = forever$getLine>>=(return.show.t.r)>>=putStrLn
