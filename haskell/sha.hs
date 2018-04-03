{-# LANGUAGE BangPatterns          #-}
{-# LANGUAGE RecordWildCards       #-}
{-# LANGUAGE DataKinds             #-}
{-# LANGUAGE ScopedTypeVariables   #-}
{-# LANGUAGE TypeOperators         #-}
{-# LANGUAGE TupleSections         #-}
{-# LANGUAGE TypeFamilies          #-}
{-# LANGUAGE LambdaCase            #-}

import           Control.Monad.Random
import           Control.Monad.Trans.Except

import           Data.Char ( isUpper, toUpper, toLower )
import           Data.List ( foldl' )
import           Data.Maybe ( fromMaybe )
import           Data.Semigroup ( (<>) )

import qualified Data.Vector as V
import           Data.Vector ( Vector )

import qualified Data.Map as M
import           Data.Proxy ( Proxy (..) )

import qualified Data.ByteString as B
import           Data.Serialize

import           Data.Singletons.Prelude
import           GHC.TypeLits

import           Numeric.LinearAlgebra.Static ( konst )

import           Options.Applicative

import           Grenade
import           Grenade.Recurrent
import           Grenade.Utils.OneHot

import           System.IO.Unsafe ( unsafeInterleaveIO )
