module pt2_gr7
import StdEnv

// NEPTUN : GAU5OE
// NAME: Maimona Emanuel Nzinga
/*
	Given a list of integer and an integer, x. 
	
	If the element of the list is even, then add with x and if odd, then subtract by x.
	
	(Add x to all the even number and subtract x to all the odd number)
	
	And then the result list should contains only elements less than 0.
	
	Let parameters be [0, -2, -3, 1] and 4  then after transforming [4, 2, -7, -3], and then the result should be [-7, -3]

*/

aux :: [Int] Int -> [Int]
aux [] _ = []
aux [x: xs] n
| x rem 2 == 0 = [x+n: aux xs n]
= [x-n: aux xs n]

myremover :: [Int] -> [Int]
myremover [] = []
myremover [x: xs]
| x >= 0 = myremover xs
= [x: myremover xs]

PT2 :: [Int] Int -> [Int]
PT2 lis n = myremover(aux lis n)

Start = PT2 [3, 2, 0, -2, -1, 10] 0 		// [-2, -1]
//Start = PT2 [-10, -15, -7, -8, -11] 8 	// [-2,-23,-15,-19]
//Start = PT2 [5, 8, -8, -5, 0, 2] 3 		// [-5, -8]
//Start = PT2 [5, 9, 7, 4, 6, 10] 2 		// []
//Start = PT2 [] 6 							// []
