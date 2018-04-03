a=filter (/='-')
b=init.a
c::[Char] -> [Integer]
c=map (read.(\s->s:[]))
d xs=zipWith (*) xs [10,9..]
e::[Integer]->Integer
e=(`mod`11).sum
f 10="X"
f n =show (11-n)
g xs = (f.e.d.c.b) xs
h xs = if g xs == [last xs] then "Right" else (init xs)++(g xs)

main = do
  
