module HW_6
import StdEnv

//Write your name and neptun code
// Name: Maimona Emanuel Nzinga
// Neptun: GAU5OE

/* Given the Major algebraic type of 4 majors and a Student record,
find the student with the highest average grade for each of the major and return their (Major, grade)
pair. The order of the resulting list is not important. */

:: Major = Finance | CS | Math | Physics

:: Student = {id :: Int, major::Major, grades::[Int]}

toString :: Major -> String
toString Finance = "Finance"
toString CS = "Cs"
toString Math = "Math"
toString Physics = "Physics"
toStirng _ = abort "It is not a Major"

average :: [Int] -> Real
average a = toReal(sum a) / toReal (length a)

getHighest :: {Student} Major -> Real
getHighest st m = last (sort [average x.grades \\ x<-:st | toString x.major == toString m])

isHighest :: Real Major {Student}-> Bool
isHighest av m st = getHighest st m == av 

highestGrades :: {Student} -> [(Real, Major)]
highestGrades st = [(avg x, mjr x) \\ x<-:st | isHighest (avg x) (mjr x) st]
where
	avg x = average x.grades
	mjr  x = x.major
	

sts1 = {{id=1,major=Finance,grades=[5,5,5,5,5]},{id=2,major=CS,grades=[5,4,2,3,5,4,5]},{id=3,major=Finance,grades=[5,4,5,3,4,5]}, {id=4,major=Physics,grades=[2,3,4,2,5]}, {id=5,major=Math,grades=[3,4,5,3,2]}, {id=3,major=CS,grades=[5,4,4,4,4]}}
sts2 = {{id=0, major=Math, grades=[3,4,2,2]}}
sts3 = {}

//Start = highestGrades sts1 // [(5, Finance), (4.2, CS), (3.2, Physics), (3.4, Math)]
//Start = highestGrades sts2 // [(2.75, Math)]
//Start = highestGrades sts3 // []

/* Given a (Tree Int), write a function which gives back a list that contains the values of the nodes that
has single subtree(which means either the right or the left child is a Leaf) */
:: Tree a = Node a (Tree a) (Tree a) 
          | Leaf
          
Tree1 :: Tree Int
Tree1 = (Node 5 (Node 10 (Node 31 (Node 1 Leaf Leaf) Leaf) Leaf) (Node 17 (Node 31 (Node 14 (Node 12 Leaf Leaf) Leaf) Leaf) (Node 11 Leaf Leaf) ))

Tree2 :: Tree Int
Tree2 = Node 0 (Node 1 (Node 3 Leaf Leaf) (Node 4 Leaf Leaf))  (Node 2 (Node 5 Leaf Leaf) (Node 6 Leaf Leaf)) 

Tree3 :: Tree Int
Tree3 = Node 0 (Node 1 (Node 3 Leaf (Node 8 Leaf Leaf)) Leaf)  (Node 2 Leaf Leaf)

isGood :: (Tree Int) -> Bool
isGood (Node x Leaf Leaf) = False
isGood (Node x (Node _ _ _) (Node _ _ _)) = False
isGood Leaf = False
isGood _ = True

singleNodes :: (Tree Int) -> [Int]
singleNodes Leaf = []
singleNodes (Node x le ri)
| isGood (Node x le ri) = [x] ++ singleNodes le ++ singleNodes ri
= singleNodes le ++ singleNodes ri

//Start = isGood (Leaf)
//Start = singleNodes Tree1 // [10,31,31,14]
//Start = singleNodes Tree2 // []
//Start = singleNodes Tree3 // [1,3]


