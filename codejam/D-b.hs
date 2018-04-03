import Text.Printf
tile k c i = 1 + sum [ (min (k - 1) (i + j)) * k ^ (c - j - 1) | j <- [0..c-1]]
tiles k c  = [ tile k c i | i <- [0,c..k-1] ]
solve k c s =
  if (c * s < k)
  then " IMPOSSIBLE"
  else foldr (++) "" (map (" " ++) $ map show $ tiles k c)
solveAll [] = ""
solveAll (x:y:z:xs) =
  "Case #" ++ (show (quot (300 - length xs) 3)) ++ ":" ++ solve x y z ++ "\n" ++ solveAll xs
main = do
  s <- readFile "/Users/a-/c:c++/codejam/D-large-practice.in"
  let inp = map read $ words s :: [Int]
  let test = head inp
  let dat = tail inp
  let ans = (solveAll dat)
  print ans
  writeFile "/Users/a-/c:c++/codejam/Dhas-large.out" ans
