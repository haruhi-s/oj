import Control.Arrow ((>>>))

type RandVar = Double -> [([Double], Double)] -- theta to pdf

listToPMF :: [([Double], Double)] -> [Double] -> Double
listToPMF xs n =
  (\x -> if x == []
         then 0
         else snd$head x)$
  filter ((==n).fst) xs

listMult :: [([Double], Double)] -> [([Double], Double)] -> [([Double], Double)]
listMult xs ys = [(x++y,a*b)| (x,a)<-xs, (y,b)<-ys]

-- the pmf function
f :: RandVar -> Double -> ([Double] -> Double) -- f(xi;theta)
f g th n = listToPMF (g th) n

jf :: [RandVar] -> Double -> ([Double] -> Double) -- f(x;theta), the joint pmf
jf xs th n = listToPMF
             (foldr listMult [([],1)] $ zipWith ($) xs (repeat th))
             n
xvec :: [RandVar]
xvec = [foo,foo,foo,foo]
xdata :: [Double]
xdata = [1,1,2,2]


l :: Double -> [RandVar] -> ([Double] -> Double) -- L(theta;x), the Likelihood function
l = flip jf

l' :: Double -> ([Double] -> Double) -- L(theta), a simplified version of L
l' = jf xvec

l'' :: Double -> Double -- L(theta), a shitty version of it which
                        -- implies that xdata has already been applied
l'' = flip (jf xvec) xdata

foo :: RandVar
foo th = [([1],(1+th)/4),([2],(1+th)/4),([3],(1-th)/2)]
