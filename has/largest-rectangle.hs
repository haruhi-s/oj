import System.IO
import Control.Arrow
import Data.List
import Control.Monad
import Control.Monad.Trans.State.Lazy

iLn :: IO [Integer]
iLn = getLine >>= (return . fmap (read) . words)

iLns :: IO [[Integer]]
iLns = getContents >>= (return . fmap (fmap (read) . words) . lines)

main = do
  xss <- iLns
  mapM_ print $ map (\xs -> fst.solve $ zip (0:tail xs) [-1,-2..]) $ init xss

solve :: [(Integer,Integer)] -> (Integer,[(Integer,Integer)])
solve = foldr (flip f) (0,[(0,0)])
  where f (m,xs@((x,j):xs_)) (n,i) =
          case compare x n of
            EQ -> (,) m xs
            LT -> (,) m $ (n,i):xs
            GT -> let (as,bs) = break ((<n).fst) xs
                      bs' = (n,snd(head as)):bs
                  in (,)
                     (maximum $ m : map (\(a,j)->(i-j)*a) as)
                     bs'

largest :: [Integer] -> Integer
largest xs = fst . solve $ zip (0:xs) [-1,-2..]

addLines :: [Integer] -> [Integer] -> [Integer]
addLines = zipWith (\a b -> b*(a+b))

denseLines :: [[Integer]] -> [[Integer]]
denseLines = scanl1 addLines

largest_m :: [[Integer]] -> Integer
largest_m = maximum . fmap largest . denseLines

t1 = getContents >>= (lines>>>fmap (words>>>fmap read)>>>denseLines>>>fmap (unwords.fmap show)>>>unlines>>>putStrLn)

t2 = replicateM 4 getLine >>= (fmap (words>>>fmap read)>>>largest_m>>>print)
