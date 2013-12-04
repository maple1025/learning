-- demo code to demonstrate haskell syntax

doubleMe x = x + x
             
doubleUs x y = x*2 + y*2
               
doubleSmallNumber x = (if x > 100 then x else x*2) + 1
                      
conanO'Brien = "It's a-me, Conan O'Brien!"

removeNonUppercase :: [Char] -> [Char]
removeNonUppercase st = [c | c <- st, c `elem` ['A'..'Z']]

factorial :: Integer -> Integer
factorial n = product [1..n]

lucky :: (Integral a) => a -> String
lucky 7 = "LUCKY NUMBER SEVEN!"
lucky x = "Sorry, you're out of luck, pal!"

sayMe :: (Integral a) => a -> String
sayMe 1 = "One!"
sayMe 2 = "Two!"
sayMe 3 = "Three!"
sayMe 4 = "Four!"
sayMe 5 = "Five!"
sayMe x = "Not between 1 and 5"

bmiTell :: (RealFloat a) => a -> a -> String
bmiTell weight height
  | bmi ^ 2 <= 18.5 = "You're underweight, you emo, you!"
  | bmi ^ 2 <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly."
  | bmi ^ 2 <= 30.0 = "You're fat! Lose some weight, fatty!"
  | otherwise                   = "You're a whale, congratulations!"
  where bmi = weight / height ^ 2

max' :: (Ord a) => a -> a -> a -> a
max' a b c
  | a > b         = a
  | otherwise     = b

myCompare :: (Ord a) => a -> a -> Ordering
a `myCompare` b
  | a > b = GT
  | a < b = LT
  | otherwise = EQ

initials :: String -> String -> String
initials firstname lastname = [f] ++ "." ++ [l] ++ "."
    where (f:_) = firstname
          (l:_) = lastname

maximum' :: (Ord a) => [a] -> a  
maximum' [] = error "maximum of empty list"  
maximum' [x] = x  
maximum' (x:xs) = max x (maximum' xs)  