import GCJ
import Text.Printf

sp :: Integer -> Integer
sp n
  | odd n  = quot n 2
  | even n = (quot n 2) - 1

-- hibit :: Integer -> Integer
hibit 1 = 1
hibit n = 2 * (hibit $ quot n 2)
hi' n = last $ takeWhile (<= n) (iterate (2 *) 1)

solve n k = " " ++ show a ++ " " ++ show b
  where a = fst $ solve' n k
        b = snd $ solve' n k


solve' n k
  | r < k-h'  = (q `quot` 2, (q - 1) `quot` 2)
  | otherwise = ((q + 1) `quot` 2, q `quot` 2)
  where h = hibit k
        h'= h - 1
        a = n - h'
        r = a `mod` h
        q = a `quot` h

solveAll [] = ""
solveAll (x:y:xs) =
  "Case #" ++ (show (quot (200 - length xs) 2)) ++ ":" ++ solve x y ++ "\n" ++ solveAll xs

main = do
  s <- readFile "/Users/a-/Downloads/C-large.in"
  let inp = map read $ words s :: [Int]
  let test = head inp
  let dat = tail inp
  printf (solveAll dat)
