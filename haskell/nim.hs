import Data.Bits
lxor :: [Int] -> Int
lxor [] = 0
lxor (x:xs) = xor x (lxor xs)
choo n (x:xs) = if x > xx
                then (0,x - xx)
                else (a+1,b)
  where a = fst $ c
        b = snd $ c
        c = choo n xs
        xx = xor n x
chooseMove xs = choo (lxor xs) xs
