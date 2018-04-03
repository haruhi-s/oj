import Data.List

f [] = Nothing
f xs = Just (v,vs)
  where v = minimum xs
        vs = delete v xs
