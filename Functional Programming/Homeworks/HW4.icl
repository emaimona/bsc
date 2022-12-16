module HW4
import StdEnv

/* Write your Neptun code here -    
	Name: Maimona Emanuel Nzinga
	Neptun : GAU5OE          
*/

/* Two lists are given. The first list contains instructive elements of what to do with the second list
1st list of char : [x,y,z] -> x => how many times to implement y function
					 		  y => the function / possible values '+' '*' '/'
					 		  z => value to use in the function
					 		  
For example if the first list is ['2', '+', '4'], it means add 4 to each element of the second list
2 times. So if the second list is [3, 10, 35] the result will be 
[3 + 4 + 4, 10 + 4 + 4, 39 + 4 + 4] = [11, 18, 47]

Try to use higher order function if possible. */

tInt :: Char -> Int
tInt x = (toInt x)- (toInt '0')

f '+' = (+)
f '-' = (-)
f '/' = (/)
f '*' = (*)

calc :: [Char] [Int] -> [Int]
calc ['0',_ , _] list2 = list2
calc [n, op, val] list2 = map ((f op) ((tInt val)*(tInt n))) list2



//Start = calc ['2', '+', '4'] [3, 10, 35] // [11, 18, 47]
//Start = calc ['0', '*', '1'] [24, 35, 56] //= [24,35,56]


/* In two dimensional list, you are given balances of clients of a bank. Each list 
represents the activities of one client. The first number is the starting balance of this month, 
and the following numbers are the deposits(+N) and the withdrawals(-N). Calculate their 
closing balance, and depending on the amount calculate their interest and add it and return in single list

Criterias of interest calculation:
if balance <= 30'000 : interest = 1%
if balance > 30'000 and balance <= 100'000  : interest = 5%
if balance > 100'000 and balance <= 200'000  : interest = 8%
if balance > 200'000 : interest = 10% (You can round up in case interest is a fractional number)


Example: interest [[50000, 900, -4000, 80000], [900, -800, 9000, 5000]] => (closing balance) [[126900], [14100]] => (interest added) [137052, 14241] */
//ceil :: Real -> Int
//ceil x
//| toReal(toInt x) == x = toInt(x)
//| toReal(toInt x) < x = toInt(x)+1
//= toInt(x)


getInterest :: Int -> Int
getInterest b
| b <= 30000 = toInt(toReal(b)*0.01)
| b > 30000 && b <= 100000 = toInt(toReal(b)*0.05)
| b > 100000 && b <= 200000 = toInt(toReal(b)*0.08)
| b > 200000 = toInt(toReal(b)*0.10)

interest :: [[Int]] -> [Int]
interest lis = map (\y = getInterest(sum y) + sum y) lis


// REMARK: considering the output of the function it can not return [[0]] because it is a list of lists.
//

//Start = interest [[0]] // [[0]]
Start = interest [[200000, -9000, 45000, -4578], [100000, 7895, -6782], [45936, -3792, 7849, 3739], [3543, 8953, -4932]] // [254564, 109202, 56419, 7640]