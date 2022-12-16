module pt1
import StdEnv

/* Write the function my_remainder which given two integers returns their remainder, 
the functon should not use any arithmetic operators except substraction, addition and comparison operators) 

You can assume that both numbers are positive */

/* Your neptun code :        */


my_remainder :: Int Int -> Int
my_remainder a b
| b==0 = abort "No division by zero"
| a < b = a
| (b+b) > a = a-b
= my_remainder a (b+b)


//Start = my_remainder 20 5 // 0
//Start = my_remainder 13 3 // 1
Start = my_remainder 3 100