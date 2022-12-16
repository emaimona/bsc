module PT6
import StdEnv

//Write your name and neptun code
// Name: Maimona Emanuel Nzinga
// Neptun GAU5OE

:: Tree a = Node a (Tree a) (Tree a) 
          | Leaf
          
Tree1 :: Tree Int
Tree1 = (Node 5 (Node 11 (Node 31 (Node 1 Leaf Leaf) Leaf) Leaf) (Node 17 (Node 31 (Node 19 (Node 7 Leaf Leaf) Leaf) Leaf) (Node 11 Leaf Leaf) ))

Tree2 :: Tree Int
Tree2 = Node 0 (Node 1 (Node 3 Leaf Leaf) (Node 4 Leaf Leaf))  (Node 2 (Node 5 Leaf Leaf) (Node 6 Leaf Leaf)) 

Tree3 :: Tree Int
Tree3 = Leaf

/* Given a tree, find the maximum value of the tree */

aux :: (Tree Int) -> [Int]
aux Leaf = []
aux (Node x le ri) = [x] ++ aux le ++ aux ri 

maxNode :: (Tree Int) -> Int
maxNode Leaf = 0
maxNode t = last (sort (aux t))

leafCount :: (Tree Int) -> Int
leafCount t = maxNode t

//Start = leafCount Tree1 // 31
//Start = leafCount Tree2 // 6
//Start = leafCount Tree3 // 0