sp :: Eq a => [a] -> [(a, [a])]
sp xs = (flip map) xs $ \x -> (x,filter (/=x) xs)
foo _ [] = []
foo 0 (xs) = [([],xs)]
foo 1 (x:xs) = [([x],xs)]
foo n (xs) = [(a++[bx],b') | (a,b) <- foo (n-1) xs, (bx,b') <- sp b]

