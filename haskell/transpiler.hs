module Transpiler where

import Data.Char
import Data.List
import Control.Monad
import Control.Applicative

alpha :: String
alpha = ['a'..'z'] ++ ['A'..'Z']

nums :: String
nums = ['0' .. '9']

-----------------------------------------------------
-------------- your parser combinator ---------------
-----------------------------------------------------

newtype Parser val = Parser { parse :: String -> [(val, String)]  }

parseCode :: Parser a -> String -> Either String a
parseCode m s = case parse m s of
  [(res, [])] -> Right res
  _           -> Left "Hugh?"
--

(<~>) :: Alternative a => a b -> a b -> a b
(<~>) = flip (<|>)

-- the code given above is not necessary
-- but they might help
-- if you have your own idea you can simply remove all of them :D

transpile :: String -> Either String String
transpile = undefined
