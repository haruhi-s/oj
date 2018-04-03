import Prelude hiding ((**),(+),(-),(*),(/))
import qualified Prelude as P ((**),(+),(-),(*),(/))
import System.IO
import Control.Arrow
import Data.List
import Control.Monad
import Control.Monad.Trans.State.Lazy

iLn :: IO [Integer]
iLn = getLine >>= (return . fmap (read) . words)

bti :: Integral a => Bool -> a
bti a = case a of
          True -> 1
          False -> 0

powMod :: Integral a => a -> a -> a -> a
powMod _ _ 0 = 1
powMod m x 1 = x `mod` m
powMod m x n2018-02-19-19:56
    | even n = powMod m modSquare (n`div`2)
    | otherwise = (x P.* powMod m modSquare ((n P.- 1)`div`2)) `mod` m
    where modSquare = x P.* (x `mod` m)

inv n = powMod 1000000007 n 1000000005

a / b = (`mod` 1000000007) (a P.* inv b)
a * b = (`mod` 1000000007) (a P.* b)
a + b = (`mod` 1000000007) (a P.+ b)
a - b = (`mod` 1000000007) (a P.- b)

main = do
  [n,m] <- iLn
  s1 <- iLn
  s2 <- iLn
  print $ solve m s1 s2

-- solve :: Integer -> [Integer] -> [Integer] -> Integer
solve m xs ys = fst . so m $ zip xs ys
so m = foldl1 g . map f
  where f (x,y) = case (x,y) of
                    (0,0) -> ((m-1)/2/m,1/m)
                    (x,0) -> ((x-1)/m,1/m)
                    (0,y) -> ((m-y)/m,1/m)
                    (x,y) -> (bti (x>y),bti $x==y)
        g (a,b) (c,d) = (a+(b*c),b*d)
