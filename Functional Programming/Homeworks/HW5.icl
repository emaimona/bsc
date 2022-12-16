module HW5
import StdEnv

//Please write your name and neptun code here
// Name Maimona Emanuel Nzinga 
// Neptun GAU5OE

/* You are given a list of tuples, where each tuple represents a complex number
(a,b) = a + b * i. Please find the absolute value of each complex number/tuple.

absolute value of complex number (a + b * i ) = sqrt(a^2 + b^2) 
Example: (5,6) = (5+6i) => |5+6i| = sqrt(25+36) = 6.40312423743285
 */

absv :: (Int, Int) -> Real
absv (x,y) = sqrt(toReal(x^2 + y^2)) 
 
absValue:: [(Int, Int)] -> [Real]
absValue lis = map absv lis


//Start = absValue [(5,6), (2,3), (-1, -4), (0,0)] // [7.81024967590665,3.60555127546399,4.12310562561766,0]
//Start = absValue [(3,-4)] // [5]
//Start = absValue [] // []

/* There is a dart competition. We have the x,y coordinate of each player's throw in a tuple.
From the list of players throw positions return the how many points they each earn.

If the dart lands outside the target, player gets 0 point.
If the dart lands in the outer circle,  1 point.
If the dart lands in the middle circle, 5 points.
If the dart lands in inner circle 10 points.

Outer circle has a radius of 10 units, middle circle 5 units, inner circle 1 unit.
The center of the dart will be at (0,0) coordinate. 

Hint : the formula of finding 2 points distance: sqrt((x2-x1)^2 + (y2-y1)^2)) */

dis :: (Int, Int) -> Int
dis (x, y) = toInt ( sqrt( toReal(x^2 + y^2) ) )

points :: Int -> Int
points x
| x <= 1 = 10
| x <= 5 = 5
| x <= 10 = 1
= 0

dart :: [(Int, Int)] -> [Int]
dart lis = map (\x = points (dis x)) lis


//Start = dart [(-3,0),(2,2),(2,6),(1,2),(0,0),(-1,0), (7,8)] // [5, 5, 1, 10, 10, 0]