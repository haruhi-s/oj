module Fibonacci where

x n= if odd n && n<0 then -n else n
(*+) ((a,b),(c,d)) ((x,e),(f,g)) = ((a*x+b*f,a*e+b*g),(c*x+d*f,c*e+d*g))
s a = a*+a

e a n = if n==0 then((1,0),(0,1)) else (if odd n then (*+a).s else s )$e a(div n 2)

fib n=fst.snd$uncurry e$ if n<0 then (((0,1),(1,-1)),-n)else(((1,1),(1,0)),n)
