import Debug.Trace
d n = foo!!n
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) =
  case c x y of
    LT -> x : merge xs (y:ys)
    GT -> y : merge (x:xs) ys
    EQ -> x : merge xs ys
foo = 1 : merge (map ((+1).(*2)) foo) (map ((+1).(*3)) foo)
c x y = trace (show x ++ cc x y ++ show y) $compare x y
cc x y
  | x < y = "<"
  | x == y = "="
  | x > y = ">"
dd n = take n foo
