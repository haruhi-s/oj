import Data.List as L

count_coins cs m =
  if fst s == m then sort.snd $ s
  else [0]
  where s = sol' cs m

sol' cs m = last.fst.break ((>m).fst) $ l cs -- the least solution-might-be
l :: [Int] -> [(Int,[Int])]
l cs = (0,[]):l' -- merged list
  where l' = merge (g cs)

f c = fmap (\(a,b)->(a+c,c:b)) -- one more coin of value C in the list

g cs = L.map ((flip f)(l cs))cs -- Needs to be merged

merge [] = []
merge ([]:xss) = merge xss
merge ((x:xs):xss) = x : m2 xs (merge xss)
-- merge2 [] ys = ys
-- merge2 xs [] = xs
-- merge2 (x@(a,b):xs) (y@(c,d):ys) =
--   case (compare a c) of
--     LT -> x:merge2 xs (y:ys)
--     GT -> y:merge2 ys (x:xs)
--     EQ -> case (compare (length b) (length d)) of
--             LT -> x:merge2 xs ys
--             otherwise -> y:merge2 xs ys

merge2 :: (a -> a -> String) -> [a] -> [a] -> [a]
merge2 f [] ys = ys
merge2 f xs [] = xs
merge2 f (x:xs) (y:ys) =
  case (f x y) of
    "x" -> x:merge2 f xs (y:ys)
    "y" -> y:merge2 f ys (x:xs)
    "X" -> x:merge2 f xs ys
    "Y" -> y:merge2 f xs ys

m2 :: (Foldable t, Ord a1) => [(a1, t a)] -> [(a1, t a)] -> [(a1, t a)]
m2 = merge2 f
  where f x@(a,b) y@(c,d) =
          case compare a c of
            LT -> "x"
            GT -> "y"
            EQ -> case (compare (length b) (length d)) of
              LT -> "X"
              otherwise -> "Y"
