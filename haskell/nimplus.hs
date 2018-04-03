import System.IO
import qualified Data.ByteString.Char8 as B
import Control.Monad
import Control.Monad.Trans.State.Lazy
import Data.Array
import Data.List
import Data.Char

iLn :: IO [Double]
iLn = getLine >>= (return . fmap (read) . words)

w :: [Integer] -> Bool
w [n] = even n
w xs = not . and . map w $ s xs

s :: [Integer] -> [[Integer]]
s n = [n]
