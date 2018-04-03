f "" = ("","")
f (x:xs) = if x == ' '
           then ("",xs)
           else (x:a,b)
  where a = fst $ f xs
        b = snd $ f xs
spli "" = []
spli s = a : spli b
  where a = fst $ f s
        b = snd $ f s

calc :: String -> Double
calc "" = 0
calc s = head $ c [] (spli s)

c :: [Double] -> [String] -> [Double]
c a [] = a
c (a:b:xs) ("+":ss) = c ((a+b):xs) ss
c (a:b:xs) ("-":ss) = c ((b-a):xs) ss
c (a:b:xs) ("/":ss) = c ((b/a):xs) ss
c (a:b:xs) ("*":ss) = c ((b*a):xs) ss
c xs (a:ss) = c ((read a):xs) ss
