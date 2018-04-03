
data Heap a = Empty | Heap a [(Heap a)]
    deriving Show

findMin :: Heap a -> a
findMin (Heap h _) = h

merge :: Ord a => Heap a -> Heap a -> Heap a
merge Empty h = h
merge h Empty = h
merge h1@(Heap x hs1) h2@(Heap y hs2)
    | x < y     = Heap x (h2:hs1)
    | otherwise = Heap y (h1:hs2)

mergePairs :: Ord a => [Heap a] -> Heap a
mergePairs []           = Empty
mergePairs [h]          = h
mergePairs (h1:h2:hs)   = merge (merge h1 h2) (mergePairs hs)

insert :: Ord a => a -> Heap a -> Heap a
insert x = merge (Heap x [])

deleteMin :: Ord a => Heap a -> Heap a
deleteMin (Heap x hs) = mergePairs hs-- b x y z = x (y z)

dm (Heap x []) = Empty'
dm (Heap x xs) = if f == x
                 then dm d
                 else d
  where d = mergePairs xs
        f = findMin d

db :: Integer -> Heap Integer-> Integer
db 0 xs = findMin xs
db n xs =
  db (n-1) $ dm . (\x -> insert (2*(findMin x)+1) x) . (\x -> insert (3*(findMin x)+1) x) $ xs
  where
    dM a
      | findMin a == findMin (deleteMin a) = dM $ deleteMin a
      | otherwise = deleteMin a



data SkewHeap a = Empty' | SkewNode a (SkewHeap a) (SkewHeap a) deriving (Show)

(+++) :: Ord a => SkewHeap a -> SkewHeap a -> SkewHeap a
heap1@(SkewNode x1 l1 r1) +++ heap2@(SkewNode x2 l2 r2)
  | x1 <= x2    = SkewNode x1 (heap2 +++ r1) l1
  | otherwise = SkewNode x2 (heap1 +++ r2) l2
Empty' +++ heap = heap
heap +++ Empty' = heap

deleteMin' (SkewNode x l r) = l +++ r
findMin'   (SkewNode x l r) = x
insert' x = (+++) (SkewNode x Empty' Empty')

db' 0 xs = findMin' xs
db' n xs =
  db' (n-1) $ dM . (\x -> insert' (2*(findMin' x)+1) x) . (\x -> insert' (3*(findMin' x)+1) x) $ xs
  where
    dM a
      | findMin' a == findMin' (deleteMin' a) = dM $ deleteMin' a
      | otherwise = deleteMin' a

dblLinear  n = db  n (Heap 1 [])
dblLinear' n = db' n (SkewNode 1 Empty' Empty')







-- c x y z = x z y
-- k x y = x
-- w x y = x y y
-- s x y z = x z (y z)
-- s' = b (b w) (b b c)
-- i x = x
-- cti f = f succ 0
insertSet :: Ord a => a -> [a] -> [a]
insertSet = insertSetBy compare

-- |  The 'insertSetBy' function is the non-overloaded version of 'insertSet'.
insertSetBy :: (a -> a -> Ordering) -> a -> [a] -> [a]
insertSetBy cmp = loop
  where
    loop x [] = [x]
    loop x (y:ys) = case cmp x y of
            LT -> x:y:ys
            EQ -> x:ys
            GT -> y:loop x ys
