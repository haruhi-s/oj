import Text.ParserCombinators.ReadP

(+-+) :: [(String,Int)] -> [(String,Int)] -> [(String,Int)]
(+-+) [] a = a
(+-+) a [] = a
(+-+) (x:xs) a = xs +-+ ins x a
  where ins x [] = [x]
        ins x@(s,n) (a@(s',n'):as) = if s == s'
                                     then (s,n+n'):as
                                     else a:(ins x as)
(***) :: Int -> [(String,Int)] -> [(String,Int)]
(***) x = map (\(s,n) -> (s,n*x))

elements = ["H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Uut", "Fl", "Uup", "Lv", "Uus", "Uuo"]

data E a = Elem a | Brackets (E a) | Mult (E a) Int | Branch (E a) (E a) deriving (Show, Eq)

ele = do s <- (choice (map string elements))
         return (Elem s)

fina = expr +++ mult +++ branch

expr =  ele +++ (brackets fina)

branch = do a <- expr +++ mult
            b <- fina
            return (Branch a b)

brackets p = (brackets1 p) +++ (brackets2 p) +++ (brackets3 p)

brackets1 p = do char '('
                 r <- p
                 char ')'
                 return $ Brackets r

brackets2 p = do char '['
                 r <- p
                 char ']'
                 return $ Brackets r

brackets3 p = do char '{'
                 r <- p
                 char '}'
                 return $ Brackets r

mult = do a <- expr
          b <- digit
          return (Mult a b)

digit = do s <- many1 (choice (map char ['0'..'9']))
           return (read s::Int)

eval (Elem a) = [(a,1)]
eval (Mult a n) = n *** (eval a)
eval (Brackets a) = eval a
eval (Branch a b) = (eval a) +-+ (eval b)

parseMolecule formula =
  if ([] == readP_to_S fina formula) || ("" /= (snd . last) (readP_to_S fina formula))
  then Left "Not a valid molecule"
  else Right (eval . fst . last $ readP_to_S fina formula)


fac 0 = 1
fac n = n * (fac $ n - 1)
c = (+1)
a n = (n+1) * (fac (n-1) - 1)
b n = - n * (c n) + a n
foo n = show (a n) ++ " - " ++ show (b n) ++ " / " ++ show (c n) ++ " = " ++ show n ++ " !\n"

bar n = map ((,)n) [2..(div n 10)]
baz n = map ((,)n) $foldr(++) []$map bar [8*(div n 9)..n]
ch (a,(b,c)) = (b `mod` c == 0) && ((a-(div b c))==(fac$div(a-b)c)) && ((a + b) `mod` c == 0)

quu x = take x $filter ch $foldr (++) []$map baz [1..]
quux (a,(b,c)) = show a ++ " - " ++ show b ++ " / " ++ show c ++ " = " ++ show (div(a-b)c) ++ " !\n"

ue mol = s $ parseMolecule mol
  where s (Right x) = show x
        s (Left x) = mol
main = do
  mol <- getLine
  putStrLn . ue $ mol
