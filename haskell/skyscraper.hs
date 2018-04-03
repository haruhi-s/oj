import Control.Arrow
import Data.List

fo = [1..4]
foo = permutations fo

bar n [] = 0
bar n (x:xs)
  = if x > n
    then 1 + bar x xs
    else bar n xs

quu xs = bar 0 xs

permLR = map (\xs -> (xs,(quu xs,quu . reverse $ xs))) foo

hintTuple [[a,b,c,d],[e,f,g,h],[i,j,k,l],[m,n,o,p]]
  = [(e,p),(f,o),(g,n),(h,m),(a,l),(b,k),(c,j),(d,i)]

clues = [[[2, 2, 1, 3],
          [2, 2, 3, 1],
          [1, 2, 2, 3],
          [3, 2, 1, 3]],
         [[0, 0, 1, 2],
          [0, 2, 0, 0],
          [0, 3, 0, 0],
          [0, 1, 0, 0]]]

opt (0,0) = foo
opt (0,x) = map fst $ filter (snd >>> snd >>> (== x)) permLR
opt (x,0) = map fst $ filter (snd >>> fst >>> (== x)) permLR
opt (x,y) = map fst $ filter (snd >>> (== (x,y))) permLR
