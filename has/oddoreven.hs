{-# LANGUAGE ExtendedDefaultRules #-}

module Kata.OddOrEven where
import Data.Bits

class (Num a,Eq a,Integral a) => I a where
  (&) :: a -> a -> a
  x :: a -> a -> a
instance I Integer where
  (&) = (.&.)
  x = xor
instance I Int where
  (&) = (.&.)
  x = xor
oddOrEven :: (I a) => [a] -> [Char]
oddOrEven n = case (foldr x 0 .fmap (&1)) n of
  0 -> "even"
  1 -> "odd"

