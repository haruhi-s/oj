module Faberge where

mo = 998244353

n `pow` k =
  if k == 0
  then 1
  else let a = (n `pow` (k`div`2)) in (mod (a * a) mo * (if (k`mod`2==1) then n else 1)) `mod` mo

inv b = b `pow` (mo-2)
di a b = (a * (inv b)) `mod` mo

height k n =
  if k > n then (2`pow`n)-1 else
    if k > n`div`2
    then
      ((2`pow`n)-2-height (n-k-1) n)`mod`mo
    else
      let rec s i (c,d) =
                if i <= k
                then let c' = (c*(n+1-i))`mod`mo
                         d' = (d*i)`mod`mo
                     in
                       rec ((s+c'`di`d')`mod`mo) (i+1) (c',d')
                else s
      in rec 0 1 (1,1)
