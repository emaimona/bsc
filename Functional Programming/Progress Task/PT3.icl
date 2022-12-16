module PT3
import StdEnv

// Write your Neptun code here:                      
// Name: Maimona Emanuel Nzinga
// Neptun: GAU5OE

/* Given 2 dimentional list of Reals, sum all the numbers inside sublist and only keep the numbers if the fraction part is equal to zero. 

Example [[1.2, 1.3, 1.5], [3.53, 53.42, 53.21]] => [4.0, 110.16] => [4] 
Hint: You can use map function (not required)    */

isZero:: Real -> Bool
isZero x = x- toReal(toInt(x))

summ [x: xs] 
|xs == [] = 0
= x + summ xs


//pt3 :: [[Real]] -> [Int]
pt3 x = filter (map (foldr (+) 0.0 ) x)

//Start = summ [1..4]
Start = pt3 [[1.2, 1.3, 1.5], [3.53, 53.42, 53.21]] // [4]
//Start = pt3 [[1.2, 1.8, 3.9], [4.8, 7.9, 6.7], [6.9]] // []