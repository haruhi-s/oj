begin = ($ ()) 
push s a k = k (a,s)
add (a,(b,s)) k = k (a+b,s)
end :: (Int,t) -> Int
end (a,s) = a
