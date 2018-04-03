import Data.List
import Data.Text (split,pack,unpack)
import Data.Char
import Control.Arrow
($>) a b = b a
infixr 0 $>

readInput :: String -> [Int]
readInput = pack >>> (split isSpace) >>> ( filter (/= pack "")) >>> (fmap (unpack >>> read))
gr _ [] = []
gr y xs =  take y xs : (gr y $  drop y xs)

s1 (n:b:x:y:xs) = (b,x,y,gr 3 xs)

main = do
  lines <- getContents
  print lines
--  lines $> readInput >>> s1 >>> print
