c m = map (`mod`3) $ let n = m-1 in scanl (\x (a,b)->x*b`div`a) 1 $ zip [1..n] [n,n-1..1]
toZ3 c = case c of
  'R'->0
  'G'->1
  'B'->2
fromZ3 n = case n of
  0->'R'
  1->'G'
  2->'B'
dot = (((`mod`3).sum). ). zipWith (*)
ltoZ3 xs = let l = length xs
               d = dot (map toZ3 xs) (c l)
           in if odd l then d else (3-d)`mod`3


solve = fromZ3.ltoZ3
