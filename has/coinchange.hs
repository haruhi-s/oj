import Control.Applicative
import Control.Monad
import System.IO
import Data.Set as S
import Data.List hiding (union,map)

main :: IO ()
main = do
    n_temp <- getLine
    let n_t = words n_temp
    let n = read $ n_t!!0 :: Int
    let m = read $ n_t!!1 :: Int
    c_temp <- getLine
    let c = fmap read $ words c_temp :: [Int]
    putStrLn . show $ l c !! n

l :: [Int] -> [Int]
l [] = 1 : repeat 0
l (x:xs) = r
  where r = zipWith (+) (l xs) (replicate x 0 ++ r)

p n = cycle (1:replicate(n-1)0)
xs *&* ys = fmap (ll xs ys) [0..]
  where ll xs ys n = sum $
                     zipWith (*) (take n ys) $ reverse (take n xs)
-- (x:xs) *&* (y:ys) = (x*y) : foldr1 (zipWith (+)) [fmap (x*) ys, fmap (y*) xs, 0:xs*&*ys]
l' xs = foldr1 (*&*) $ fmap p xs
--l [x] = cycle (1:replicate(x-1)0)

-- ll :: [Int] -> [Set [Int]]
-- ll xs = fromList [[]] : (foldr1 (zipWith union) $ g <$> xs)
--   where g s = replicate (s-1) (fromList []) ++ (fmap.S.map) (sort.(s:)) (ll xs)






getMultipleLines :: Int -> IO [String]

getMultipleLines n
    | n <= 0 = return []
    | otherwise = do
        x <- getLine
        xs <- getMultipleLines (n-1)
        let ret = (x:xs)
        return ret
