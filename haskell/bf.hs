import Data.Char
import Debug.Trace

plus a = mod (succ a) 256
minus a = mod (a-1) 256
unj (Just a) = a

--bf ll m rr pp (n:ns) ii | trace ("bf "++show (n:ns))False = undefined
-- bf :: [Int] -> Int -> [Int] -> [Char] -> [Char] -> [Int] -> Maybe [Int]
bf _ _ _ _ "" _ = Just []
bf ll@(l:ls) m rr@(r:rs) pp@(p:ps) (n:ns) ii =
  case n of
    '+' -> bf ll (plus m) rr (n:pp) ns ii
    '-' -> bf ll (minus m) rr (n:pp) ns ii
    '>' -> bf (m:ll) r rs (n:pp) ns ii
    '<' -> bf ls l (m:rr) (n:pp) ns ii
    '.' -> let x = (bf ll m rr (n:pp) ns ii) in
             if x == Nothing
             then Nothing
             else Just $ m:(unj x)
    ',' -> if ii == []
           then Nothing
           else bf ll (head ii) rr (n:pp) ns (tail ii)
    '[' -> if m == 0
           then skip ll m rr (n:pp) ns ii 1
           else bf ll m rr (n:pp) ns ii
    ']' -> if m == 0
           then bf ll m rr (n:pp) ns ii
           else skip' ll m rr pp (n:ns) ii 1

--skip ll m rr pp n ii c | trace ("skip "++show c)False = undefined
skip ll m rr pp (n:ns) ii c
  = if c == 0
    then bf ll m rr pp (n:ns) ii
    else case n of
         '[' -> skip ll m rr (n:pp) ns ii (c+1)
         ']' -> skip ll m rr (n:pp) ns ii (c-1)
         otherwise -> skip ll m rr (n:pp) ns ii c
skip' ll m rr (p:ps) (n:ns) ii c
  = if c == 0
    then bf ll m rr (p:ps) (n:ns) ii
    else case p of
           '[' -> skip' ll m rr ps (p:n:ns) ii (c-1)
           ']' -> skip' ll m rr ps (p:n:ns) ii (c+1)
           otherwise -> skip' ll m rr ps (p:n:ns) ii c

b source input =
  (bf l0 0 l0 "   " (source++"+++++") (map ord input)) >>= (\x -> Just (map chr x))
  where l0 = repeat 0
