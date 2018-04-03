import Data.List
import Data.Text (split,pack,unpack)
import Data.Char
import Control.Arrow
($>) a b = b a
infixr 0 $>

readInput :: String -> [Int]
readInput = pack >>> (split isSpace) >>> ( filter (/= pack "")) >>> (fmap (unpack >>> read))

grp (x:y:xs) = gr y xs
  where gr _ [] = []
        gr y xs =  take y xs : (gr y $  drop y xs)

l =  map (\s ->  map (subtract $  minimum s) s)
r a =  map  minimum a

l' x =  transpose $l ( transpose x)
r' a = r $ transpose a

a = ((l &&& r) >>> (\ (x,y) -> (l' x,(y,(r' x))) ))
aa = ((l' &&& r') >>> (\ (x,y) -> (l x,((r x),y)) ))

a' x = if comp (a x) (aa x)
       then a x
       else aa x
  where comp (_,(a,b)) (_,(c,d)) = sum a + sum b < sum c + sum d

b (x,(a,b)) = if (0 < maximum (map maximum x))
          then "-1"
          else ((flip (++)$"\n"). show . length &&& foldr (++) "") >>> uncurry (++) $(c "row " a)++(c "col " b)
c s n =  filter ((/=0).snd) >>> map (\(i, t)-> take (fromIntegral t) $repeat $s ++ show i++"\n") >>>foldr (++) [] $z n
z = zipWith(,)[1..]
main = do
  lines <- getContents
  putStr$ (b.a') (grp $readInput lines)
