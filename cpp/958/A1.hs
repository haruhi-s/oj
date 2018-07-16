import System.IO
import Control.Arrow
import Data.List
import Control.Monad

iLn :: IO [Int]
iLn = getLine >>= (return . fmap (read) . words)

main = do
  [n,m] <- iLn
  m1 <- replicateM n getLine
  m2 <- replicateM m getLine
  let xs_ = [id,map reverse,reverse,map reverse.reverse]
  let xs = xs_++(map (transpose.) xs_)
  let ans=any ((m1==).($m2)) xs
  putStrLn (if ans then "Yes" else "No")
