module Imperative (
  def, var, lit, while, (+=), (-=), (*=)
) where
import Control.Monad
import Control.Monad.State
import Control.Arrow
import Control.Applicative

data M a = W ((Integer -> Integer, Integer) -> (a,(Integer -> Integer, Integer)))
data V = I Integer
ui (I a) = a

instance Functor M where
  fmap  = liftA

instance Applicative M where
  pure x = W (\(f,i)->(x,(f,i)))
  (<*>) = ap

instance Monad M where
  return = pure
  (>>=) = undefined

def :: (M V) -> Integer
def r         = undefined
var :: Integer -> M V
var v         = undefined
lit :: Integer -> V
lit l         = undefined
-- while :: V -> (Integer -> Bool) -> M () -> M ()
while r f act = do
  if (f $ ui r)
  then act >> while r f act
  else return ()


a += b = undefined
a -= b = undefined
(*=) :: V -> V -> M ()
a *= b = undefined

factorial :: Integer -> Integer
factorial n = def $ do
  result <- var 1
  i      <- var n
  while i (>0) $ do
    result *= i
    i      -= lit 1
  return result
