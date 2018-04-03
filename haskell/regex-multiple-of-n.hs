import Data.List
import Data.List.Utils hiding (replace)

data R = Lit Integer
       | Zero | One
       | Many R
       | OneOf [R]
       | Grp [R]
  deriving (Show,Eq)

replace :: Eq a => [a] -> [a] -> [a] -> [a]
replace old new = join new . split old
f p = map (\n->(mod (2*n)p,mod (2*n+1)p)) [0..p-1]
g n = reverse $ h $ map (\ x ->
             (++)
             (map ((\x->"["++x++"]0").show)$findIndices((==x).fst)(f n))
             (map ((\x->"["++x++"]1").show)$findIndices((==x).snd)(f n))
          )
      [0..n-1]
      where
        h (x:y:xs) = (x++["0"]):(y++["1"]):xs



r xs = zipWith foo xs $ map (\x->"["++show x++"]") $reverse [0..length xs-1]

foo ys n = if baz /= [] then baz else ys
  where
    baz = bar n <$> a <*> b
    a = filter (n`isPrefixOf`) ys
    b = filter (not.(n`isPrefixOf`)) ys

bar n x y = y ++ "(" ++ replace n "" x ++ ")*" 
quu (x:xs) = map (quux x) xs
  where
    l = "[" ++ show (length xs) ++ "]"
    quux ys zs = zs' ++ (qu ys zs'')
      where
        zs' = filter (not.(l`isInfixOf`)) zs
        zs'' = filter (l`isInfixOf`) zs
    qu as bs = (\a b -> replace l a b) <$> as <*> bs

it (x:[]) = [x]
it (x:xs) = it$quu.r$(x:xs)
ans n = (join "|").head$it$g n
