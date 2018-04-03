import Data.List (transpose,intersperse)
import Control.Monad (liftM,replicateM)

join :: [a] -> [[a]] -> [a]
join delim l = concat (intersperse delim l)

change :: [[Bool]] -> [[Bool]]
change m = fmap a b
  where b = fmap and $ m
        a True = c
        a False = c'
        c' = map (const False) (head m)
        c = fmap and . transpose $ m

ib 1 = True
ib 0 = False

bi True = 1
bi False = 0

change' :: [[Int]] -> [[Int]]
change' = fmap (fmap bi) . change . fmap (fmap ib)

readLN :: IO [Int]
readLN = do
  a <- getLine
  return $ map readi . words $ a

pr =  putStrLn . join "\n" . fmap (join " " . fmap show)

readi :: String -> Int
readi = read
main = readLN >>= return . head >>= flip replicateM readLN >>= return . change' >>= pr
