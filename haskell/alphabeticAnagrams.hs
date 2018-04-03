import Data.List

lexiPos :: String -> Integer
lexiPos s = l s (fromIntegral (length s)) $ gr s
  where l "" _ _ = 1
        l (x:xs) n g = (pp x n g) +  (l xs (n-1) $ d x g)
        d x [] = undefined
        d x (a@(m,n):as) = if x == m
                           then (m,n-1):as
                           else a:(d x as)
        pp x n g = sum $ map ((\x' -> p x' n g) . fst) $ filter ((> 0) . snd) $ takeWhile ((< x) . fst ) g
        p :: Char -> Integer -> [(Char, Integer)] -> Integer
        p x n g = (f (n-1)) `div` (ff (d x g))
        ff = product . (map (f . snd))


f n = product [1..n]

gr :: String -> [(Char, Integer)]
gr xs = sort $ g xs []
  where g "" a = a
        g (x:xs) a = g xs $ ins x a
        ins x [] = [(x,1)]
        ins x (a@(m,n):as) = if x == m
                             then (m,1 + n):as
                             else a : (ins x as)


