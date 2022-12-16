module HW1
import StdEnv

/* 
	Name: Maimona Emanuel Nzinga
	Neptun: GAU50E
*/


/* Student recently learned Fibonacci numbers, but he got bored of the problems.
	So, he decided to try his own new sequence:
		f(0) = a
		f(1) = b
		f(n) = f(n-1) ^ f(n-2) where ^ denotes bitxor operation (Hint: bitxor operator can be found in the documentation)
	Given a, b, and n, make a function to help him calculate the nth number in his sequence.
	For example:
	
*/

diffFibonacchi :: Int Int Int -> Int
diffFibonacchi a b n
| n==0 = a
| n==1 = b
| otherwise = (bitxor) (diffFibonacchi a b (n-1)) (diffFibonacchi a b (n-2))
//Start = diffFibonacchi 86 77 15 // = 86




/* Auxialiary function to give the sumOfDigits */
sumOfDigits :: Int -> Int
sumOfDigits n
| n==0 = 0
| otherwise = (n rem 10) + sumOfDigits(n/10)



/* Given three numbers, determine if any of the two numbers addition's sum of digits produces a lucky number.
A lucky number is a number whose sum of digits is divisible by 3 */

isThereLucky :: Int Int Int -> Bool
isThereLucky a b c 
| sumOfDigits(a+b) rem 3 == 0 = True
| sumOfDigits(a+c) rem 3 == 0 = True
| sumOfDigits(b+c) rem 3 == 0 = True
| otherwise = False

Start = isThereLucky 12 5 9






