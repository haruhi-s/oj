fix :: (a -> a) -> a
fix f = let x = f x in x

--rev :: [a] -> [a] -> [a]
--rev [] a = a
--rev (x:xs) a = rev xs (x:a)

--fr f z [] = z
--fr f z (x:xs) = f x $ fr f z xs

r :: ([a] -> [a]) -> [a] -> [a]
r f [] = []
r f (x:xs) = (f xs) ++ [x]

f :: ((a -> b -> b) -> b -> [a] -> b) -> (a -> b -> b) -> b -> [a] -> b
f ff g z [] = z
f ff g z (x:xs) = g x $ ff g z xs

rev :: [a] -> [a]
rev [] = []
rev (x:xs) = (rev xs) ++ [x]


e1=1+(e2+e4)/2
e2=1+(e1+e3+e5)/3
e3=1+e2
e4=1+e1
e5=1+e2/2
