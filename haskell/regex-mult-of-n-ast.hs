import Data.List

data R = Lit Int
       | Zero | One
       | Many R
       | OneOf [R]
       | Grp [R]
  deriving (Show,Eq)

inn :: R -> R -> Bool
a@(Lit n) `inn` (Lit m) = n == m
a@(Lit n) `inn` (Many x) = a `inn` x
a@(Lit n) `inn` (OneOf xs) = and$map (a `inn`) xs
a@(Lit n) `inn` (Grp xs) = and$map (a `inn`) xs
a@(Lit n) `inn` _ = False


replace :: Int -> R -> R -> R
replace n new (Lit m) = if n == m then new else (Lit m)
replace n new (Many x) = Many $ replace n new x
replace n new (OneOf xs) = OneOf $ map (replace n new) xs
replace n new (Grp xs) = Grp $ map (replace n new) xs
replace _ _   a = a

f p = map (\n->(mod (2*n)p,mod (2*n+1)p)) [0..p-1]
g n = reverse $ map OneOf $ h $ map (\ x ->
             (++)
             (map (\y->Grp [Lit y,Zero])$findIndices((==x).fst)(f n))
             (map (\y->Grp [Lit y, One])$findIndices((==x).snd)(f n))
          )
      [0..n-1]
      where
        h (x:y:xs) = (x++[Zero]):(y++[One]):xs

r :: [R] -> [R]
r xs = zipWith foo xs $ map Lit $reverse [0..length xs-1]

foo :: R -> R -> R
foo x a@(Lit n) = undefined
