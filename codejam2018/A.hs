import System.IO
import Control.Arrow
import Control.Monad

iLn :: IO [Integer]
iLn = getLine >>= (return . fmap (read) . words)

main = do
  [t] <- iLn
  foldM_ test () [1..t]

test () i = do
  [d',s] <- getLine >>= (return . words)
  let d = read d' :: Integer
  let (sumofs,xs)=s_tolist s
  putStrLn $ "Case #"++show i++": "++
    if head xs<=d
    then show$solve (sumofs-d) $ reverse $ zip ((2^)<$>[0..]) $tail xs
    else "IMPOSSIBLE"

solve diff ((x,y):xs) =
  if diff <= 0
  then 0
  else if y==0
       then solve diff xs
       else 1+solve (diff-x) ((x,y-1):xs)

tolist :: String -> (Integer,[Integer])
tolist "" = (0,[0])
tolist ('C':xs) = (*2)***(0:) $ tolist xs
tolist ('S':xs) = succ***((:) <$> (succ.head) <*> tail) $ tolist xs

s_tolist = (second)(scanr1 (+)) . tolist

