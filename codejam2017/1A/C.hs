import Text.Printf

ceilQuot a b = a `quot` b + if a `mod` b == 0 then 0 else 1
stepToKill ad hk b n =
  if steps n <= steps (n+1)
  then steps n
  else stepToKill ad hk b (n+1)
  where
    steps n = (n + (hk `ceilQuot` (ad+n*b)))

solve hd ad hk ak b d =
  if steps <= hd `ceilQuot` ak
  then show steps
  else "IMPOSSIBLE"
  where
    steps = stepToKill ad hk b 0

solveAll [] = ""
solveAll (a:b:c:d:x:y:xs) =
  "Case #" ++ (show (quot (600 - length xs) 6)) ++ ":" ++ solve a b c d x y ++ "\n" ++ solveAll xs

main = do
  s <- readFile "/Users/a-/Downloads/C-large.in"
  let inp = map read $ words s :: [Int]
  let test = head inp
  let dat = tail inp
  printf (solveAll dat)
