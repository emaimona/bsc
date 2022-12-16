module PT4
import StdEnv

//Please write your name and NEPTUN code - 
// Name Maimona Emanuel Nzinga
// Neptun GAU5OE
    
/* 2 students are playing dice game. In reach round they throw a dice, their results given in a
list. Student win if their sum of throws is higher. Determine which student will win.
Return 0 - draw
	   1 - 1st student wins
	   2 - 2nd student wins
Example:
student A, student B = [[1,2],[5,6],[3,6]] = (9, 14) = 2 (student B wins)
 */

aux lis = [sum x \\ x<-lis]

max [] i = i
max [x: xs] i
| x > i = max xs x
= max xs i

index [] _ _ = -1
index [x:xs] y i
| x == y = i
= index xs y (i+1)




//pt4 :: [[Int]] -> Int
pt4 lis =  index (aux lis) (max (aux lis) 0) 0 


//Start = pt4 [[1,2],[5,6],[3,6]] // 2
Start = pt4 [[1,4], [5,2], [4,4], [3,1]] // 1
//Start = [[4,2], [2,4]] // 0
