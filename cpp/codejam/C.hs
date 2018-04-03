import Numeric
import Data.Char
import Text.Printf
main = do
  let ans = "Case #1:\n" ++ (foldr (++) "" $ ((map (\x -> showIntAtBase 2 intToDigit x " "++(foldr (\x y -> x++" "++y) "" $ map show $ [x^16+1| x <- [2..10]])++"\n") $ [ (2 ^ 16 + 1) * (2 * i + 2 ^ 15 + 1)  | i <- [1..500] ])))
  printf ans
  writeFile "/Users/a-/c:c++/codejam/Chas-large.out" ans



   -- foldr (\x y -> x++" "++y) "" $ map show $ [x^16+1| x <- [2..10]]
