import System.Environment
merge xs [] = xs
merge [] xs = xs
merge xx@(x:xs) yy@(y:ys) =
  if (x<y)
  then x:(merge xs yy)
  else y:(merge xx ys)
msort xs = case xs of
  [] -> []
  [a] -> [a]
  _   -> uncurry merge $ (\(x, y)-> (msort x,msort y) ) $ splitAt ((length xs) `div` 2) xs

main = getArgs >>= print
