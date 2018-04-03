module TinyThreePassCompiler where
import Text.ParserCombinators.ReadP
import Data.List
shouldPass1 a b = (pass1 a) == b
data AST = Imm Int
         | Targ [Char]
         | Bracket AST
         | Arg Int
         | Add AST AST
         | Sub AST AST
         | Mul AST AST
         | Div AST AST
         deriving (Eq, Show)

data Token = TChar Char
           | TInt Int
           | TStr String
           deriving (Eq, Show)

alpha, digit :: String
alpha = ['a'..'z'] ++ ['A'..'Z']
digit = ['0'..'9']

tokenize :: String -> [Token]
tokenize [] = []
tokenize xxs@(c:cs)
  | c `elem` "-+*/()[]" = TChar c : tokenize cs
  | not (null i) = TInt (read i) : tokenize is
  | not (null s) = TStr s : tokenize ss
  | otherwise = tokenize cs
  where
    (i, is) = span (`elem` digit) xxs
    (s, ss) = span (`elem` alpha) xxs

compile :: String -> [String]
compile = pass3 . pass2 . pass1

unj (Just a) = a
split     :: (Char -> Bool) -> String -> [String]
split p s =  case dropWhile p s of
               "" -> []
               s' -> w : split p s''
                            where (w, s'') = break p s'
removeSpace "" = ""
removeSpace (' ':xs) = removeSpace xs
removeSpace (x:xs) = x:(removeSpace xs)
par s = fst.last$readP_to_S expression (reverse . removeSpace $ s)
ar s a = (elemIndex a) . (split (==' ')) . head . (split (==']')) $ tail s


pass1 :: String -> AST
pass1 s = subst$par e
  where e = last . (split (==']')) $ s
        arg a = (elemIndex a) . (split (==' ')) . head . (split (==']')) $ tail s
        subst (Bracket a) = subst a
        subst (Targ s) = (Arg (unj . arg $ reverse s))
        subst (Mul a b) = (Mul (subst b) (subst a))
        subst (Div a b) = (Div (subst b) (subst a))
        subst (Add a b) = (Add (subst b) (subst a))
        subst (Sub a b) = (Sub (subst b) (subst a))
        subst a = a
digits = do s <- many1 (choice (map char ['0'..'9']))
            return (Imm (read (reverse s)::Int))
var = do s <- many1 (choice (map char alpha))
         return (Targ s)
brackets = do char ')'
              s <- expression
              char '('
              return (Bracket s)
factor = brackets +++ var +++ digits
mul = do a <- factor
         char '*'
         b <- term
         return (Mul a b)
divi = do a <- factor
          char '/'
          b <- term
          return (Div a b)
term = factor +++ mul +++ divi
expression = term +++ plus +++ minus
plus = do a <- term
          char '+'
          b <- expression
          return (Add a b)
minus = do a <- term
           char '-'
           b <- expression
           return (Sub a b)








isImm (Imm _) = True
isImm _ = False
isArg (Arg _) = True
isArg _ = False
pass2 :: AST -> AST
pass2 (Add (Imm a) (Imm b)) = (Imm (a+b))
pass2 (Sub (Imm a) (Imm b)) = (Imm (a-b))
pass2 (Mul (Imm a) (Imm b)) = (Imm (a*b))
pass2 (Div (Imm a) (Imm b)) = (Imm (a `div` b))

pass2 (Add a b) = pass2' (Add (pass2 a) (pass2 b))
pass2 (Sub a b) = pass2' (Sub (pass2 a) (pass2 b))
pass2 (Mul a b) = pass2' (Mul (pass2 a) (pass2 b))
pass2 (Div a b) = pass2' (Div (pass2 a) (pass2 b))
pass2 a = a
pass2' (Add (Imm a) (Imm b)) = (Imm (a+b))
pass2' (Sub (Imm a) (Imm b)) = (Imm (a-b))
pass2' (Mul (Imm a) (Imm b)) = (Imm (a*b))
pass2' (Div (Imm a) (Imm b)) = (Imm (a `div` b))
pass2' a = a

pass3 :: AST -> [String]
pass3 (Arg n) = ["AR "++show n,"PU"]
pass3 (Imm n) = ["IM "++show n,"PU"]
pass3 (Add a b) = (pass3 a) ++ (pass3 b) ++ ["PO","SW","PO","AD","PU"]
pass3 (Sub a b) = (pass3 a) ++ (pass3 b) ++ ["PO","SW","PO","SU","PU"]
pass3 (Mul a b) = (pass3 a) ++ (pass3 b) ++ ["PO","SW","PO","MU","PU"]
pass3 (Div a b) = (pass3 a) ++ (pass3 b) ++ ["PO","SW","PO","DI","PU"]

simulate :: [String] -> [Int] -> Int
simulate asm argv = takeR0 $ foldl' step (0, 0, []) asm where
  step (r0,r1,stack) ins =
    case ins of
      ('I':'M':xs) -> (read xs, r1, stack)
      ('A':'R':xs) -> (argv !! n, r1, stack) where n = read xs
      "SW" -> (r1, r0, stack)
      "PU" -> (r0, r1, r0:stack)
      "PO" -> (head stack, r1, tail stack)
      "AD" -> (r0 + r1, r1, stack)
      "SU" -> (r0 - r1, r1, stack)
      "MU" -> (r0 * r1, r1, stack)
      "DI" -> (r0 `div` r1, r1, stack)
  takeR0 (r0,_,_) = r0
