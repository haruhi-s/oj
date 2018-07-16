import Prelude hiding (foldr)
import System.IO
import Control.Arrow
import Data.List hiding (foldr)
import Control.Monad
import Data.Array
import Data.Foldable (foldr)

main = do
  [m,d] <- iLn
  let getSubs = do
        [k] <- iLn
        vs  <- replicateM k dLn
        return vs
  subspaces <- replicateM m getSubs >>= return . listArray (1,m). map snd. zip [1..] . map (simplify.rref)
  let (c,ma,ans) = (1,listArray (1,m) (repeat [[0]]),listArray (1,m) (repeat 0)) :: (Int, Array Int [[Double]], Array Int Int)
  let (_,_,ans_) = foldl (flip upd) (c,ma,ans) $assocs subspaces
  -- traverse print subspaces
  putStrLn $foldr1 (\a b-> a++" "++b) $map show$ elems ans_
  return subspaces

upd (n,matr) (c,ma,ans) =
  if matr `elem` elems ma
  then (c,ma,ans//[(n,matr `ind` ma)])
  else (c+1,ma//[(c,matr)],ans//[(n,c)])

ind matr ma = fst.head.filter((==matr).snd)$assocs ma

simplify :: [[Double]] -> [[Double]]
simplify = takeWhile (not.all (==0))

rref :: (Eq a,Fractional a) => [[a]] -> [[a]]
rref m = f m 0 [0 .. rows - 1]
  where rows = length m
        cols = length $ head m

        f m _    []              = m
        f m lead (r : rs)
            | indices == Nothing = m
            | otherwise          = f m' (lead' + 1) rs
          where indices = find p l
                p (col, row) = m !! row !! col /= 0
                l = [(col, row) |
                    col <- [lead .. cols - 1],
                    row <- [r .. rows - 1]]
                Just (lead', i) = indices
                newRow = map (/ m !! i !! lead') $ m !! i
                m' = zipWith g [0..] $
                    replace r newRow $
                    replace i (m !! r) m
                g n row
                    | n == r    = row
                    | otherwise = zipWith h newRow row
                  where h = subtract . (* row !! lead')

replace :: Int -> a -> [a] -> [a]
replace n e l = a ++ e : b
  where (a, _ : b) = splitAt n l

iLn :: IO [Int]
iLn = getLine >>= (return . fmap (read) . words)
dLn :: IO [Double]
dLn = getLine >>= (return . fmap (read) . words)
