hitsHoop :: [((Double,Double),Double)] -> ((Double,Double),Double) -> (Double,Double) -> Bool
hitsHoop xs ball hoop = and $ map (\x -> eD ball x hoop) xs

cros (x,y) ((a,b), (c,d)) =
  if (b<=y) && (y<=d)
  then (if (m-m')/(n-n')*(n)+m <= 0
        then 1
        else 0)
  else 0
  where m = a - x
        n = b - y
        m' = c - x
        n' = d - y
lin [[a, b], [c, d]] (x,y) = (a*x+b*y,c*x+d*y)
mat = [[1,0],[0,1]]
pointInPoly poly point =
  odd $ sum $ (cros point' ((head poly'), (last poly'))) : map (cros point') [ (a,b) | a <- tail poly', b <- init poly']
  where poly' = map (lin mat) poly
        point' = lin mat point
eD :: ((Double,Double),Double) -> ((Double,Double),Double) -> (Double,Double) -> Bool
eD ((bx,by),bv) ((dx,dy),dv) (hx,hy) =
  if dv >= bv
  then inC
  else inC || inT
  where x = dx - hx
        y = dy - hy
        bh = sqrt ((bx-hx)^2+(by-hy)^2)
        inC = x^2 + y^2 > bh^2 * (dv/bv)^2
        inT = pointInPoly [(bx,by)] (dx,dy)
