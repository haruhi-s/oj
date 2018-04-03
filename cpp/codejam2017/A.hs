import GCJ

sp :: Integer -> Integer
sp n
  | odd n  = quot n 2
  | even n = (quot n 2) - 1

hibit :: Integer -> Integer
hibit 1 = 1
hibit n = 2 * (hibit $ quot n 2)

solve n k
  | r < k-h'  = (q `quot` 2, (q - 1) `quot` 2)
  | otherwise = ((q + 1) `quot` 2, q `quot` 2)
  where h = hibit k
        h'= h - 1
        a = n - h'
        r = a `mod` h
        q = a `quot` h
        q'= q - 1
