module SimpleInteractiveInterpreter where
import Data.Fixed
import Text.ParserCombinators.ReadP

data Interpreter = I [(String,Double)] [(String,AST)]
type Result = Maybe Double

newInterpreter :: Interpreter
newInterpreter = I [] []

input :: String -> Interpreter -> Either String (Result, Interpreter)
input _ _ = Left "Not implemented"


data AST = Imm Double
         | Targ String
         | Bracket AST
         | Arg Int
         | Add AST AST
         | Sub AST AST
         | Mul AST AST
         | Div AST AST
         | Mod AST AST
         | FunCall AST [AST]
         | FunDef AST [String] AST
         | VarDef AST AST
         | Conc AST AST
         | Nill
         deriving (Eq, Show)
spaces = do many $ char ' '
space1 = do many1$ char ' '
spacei = do{char ' ';return (\a b -> (Conc a b))}
var    = do a <- many1 (choice (map char ['a'..'z']))
            return (Targ a)
number = do a <- many1 (choice (map char ['0'..'9']))
            char '.'
            b <- many1 (choice (map char ['0'..'9']))
            return (Imm (read $a++"."++b))

digits = do s <- many1 (choice (map char ['0'..'9']))
            return (Imm (read s))

brackets = do char '('
              a <- expressio
              char ')'
              return a
conv :: AST -> [String]
conv Nill = []
conv (Targ a) = [a]
conv (Conc (Targ a) b) = a:(conv b)
funCall = undefined
funcDef = do string "fn"
             space1
             n <- var
             space1
             a <- chainl var spacei Nill
             spaces
             string "=>"
             spaces
             b <- expression
             return (FunDef n (conv a) b)
varDef = do n <- var
            spaces
            char '='
            spaces
            e <- expressio
            return (VarDef n e)

op0 = do{spaces;a <- brackets +++ digits +++ number +++ var;spaces;return a}
factor = do{spaces;a <- op0 +++ (chainl1 op0 (mul +++ divi));spaces;return a}

mul = do{char '*';return (\a b -> (Mul a b));}
divi = do{char '/';return (\a b -> (Div a b));}

add = do{char '+';return (\a b -> (Add a b));}
sub = do{char '-';return (\a b -> (Sub a b));}
expression = chainl1 factor $add+++sub
expressio = expression +++ varDef
