import Data.List
import Numeric
import Data.Char
import Control.Monad
f (-1) = 0
f 0 = 0
f x = (b+1)*(count a)+c+10*(f $a-1)+a
  where a = x `div` 10
        b = x `mod` 10
        c = if b > 0 then 1 else 0
count n = length . filter (=='1') $ show n

g a b = f b - f (a-1)


h (-1) = 0
h 0 = 0
h x = (b+1)*(count' a)+c+2*(h $a-1)+a
  where a = x `div` 2
        b = x `mod` 2
        c = if b > 0 then 1 else 0
count' n = fromIntegral$length . filter (=='1') $
           showIntAtBase 2 intToDigit n ""

g' :: Integer -> Integer -> Integer
g' a b = h b - h (a-1)
