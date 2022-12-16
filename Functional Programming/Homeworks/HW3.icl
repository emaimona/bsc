module HW3
import StdEnv

/* Please enter your name and neptun code here            
	Name: Maimona Emanuel Nzinga
	Neptun: GAU5OE
*/

// Try to use higher order functions if you can

/* 1. Given a list of numbers return the index of the number that including that
number the sum of all previous numbers equals 0.

Example:
equalsZero [1,2,3,-3,-2,-1,3,4,1,-1] = 5
which is the index of -1. The sum of [1,2,3,-3,-2,-1] is zero.
If there is no such number return -1 */

zeroSum :: [Int] Int Int -> Int
zeroSum [] _ _ = -1
zeroSum [x: xs] s count
| s == 0 = count
= zeroSum xs (s+x) (count+1)

equalsZero :: [Int] -> Int
equalsZero [] = -1
equalsZero [0:_] = 0
equalsZero [x: xs] = zeroSum xs x 0


//Start = equalsZero [1,2,3,-3,-2,-1,3,4,1,-1]

/* 2. Accountants are always interested in finding numbers that contain the digit 7. 
Implement a function that filters if the number does not contain digit 7
Example: 
hasSeven [3, 13, 27, 771, 674, 301] = [27, 771, 674] */

containSeven :: Int -> Bool
containSeven 0 = False
containSeven x
| x rem 10 == 7 = True
= containSeven (x/10)


hasSeven :: [Int] -> [Int]
hasSeven [] = []
hasSeven x = filter containSeven x

//Start = hasSeven [3, 13, 27, 771, 674, 301]









