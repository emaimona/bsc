module HW2_1
import StdEnv


/* Please write your name and Neptun code here -              
	Name: Maimona Emanuel Nzinga
	Neptun: GAU5OE
*/

/* 1.  keep the middle element of every sublist, if the length of the sublist is odd.
If it is even ignore that sublist 
 e.g. [[1, 2, 3], [3, 4], [5, 7, 8, 9], [11,12,13] -> [2, 12] */

removeMiddle :: [[Int]] -> [Int]
removeMiddle [] = []
removeMiddle [x: xs]
| length x rem 2==0 = removeMiddle xs
= [ hd (drop (length x/2) x): removeMiddle xs]

//Start = removeMiddle [[1,27, 56, 44], [4,22, 29], [8,16, 29]]// [22, 16]
//Start = removeMiddle [[1,5], [2,4], [3,3]] // []
//Start = removeMiddle [] // []



/* 2. Write a function gaps that gives all the possibilities to take out one element from a list. 
For example:
gaps [1,2,3,4,5] = [[2,3,4,5], [1,3,4,5], [1,2,4,5], [1,2,3,5], [1,2,3,4]] */

take:: Int [Int] -> [Int]
take _ [] = []
take pos [x: xs]
| pos > length [x: xs] = [x:xs]
| pos == 1 = xs
= [x: take (pos-1) xs]

mygaps:: Int [Int] -> [[Int]]
mygaps pos x
| pos>length x = []
= [take pos x: mygaps (pos+1) x]

gaps :: [Int] -> [[Int]]
gaps [] = []
gaps x = mygaps 1 x

//Start = gaps [1,2,3,4,5] // [[2,3,4,5], [1,3,4,5], [1,2,4,5], [1,2,3,5], [1,2,3,4]] 
Start = gaps [] // []



