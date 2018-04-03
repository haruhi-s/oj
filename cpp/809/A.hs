import Data.List
import Data.Text (split,pack,unpack)
import Data.Char
import Control.Arrow

readInput :: String -> [Int]
readInput = pack >>> (split isSpace) >>> (filter (/= pack "")) >>> (fmap (unpack >>> read))

($>) a b = b a
infixr 0 $>


main = do
  print$  (\a ->
             (\x ->
                \b ->
                  (\y z->
                     (x y)
                  )
                (1+b) b
             )
            ((,)a)
            a
          )
    2


s [] = [[]]
s (x:xs) =
  (s xs) ++
  (map (x:) $s xs)
