module PT7
import StdEnv

// Name Maimona Emanuel Nzinga
// Neptun GAU5OE

/* Overload the built-in operators so that sort is usable on Tree type.
tree1 < tree2 if sum of all the node values of tree1 is less than tree2 */

:: Tree a = Node a (Tree a) (Tree a) | Leaf

btree = Node 4 (Node 2 (Node 1 Leaf Leaf)(Node 3 Leaf Leaf)) (Node 6 (Node 5 Leaf Leaf)(Node 7 Leaf Leaf))

ctree = Node 1 (Node 2 (Node 8 Leaf Leaf)(Node 9 (Node 4 (Node 16 Leaf Leaf) Leaf) Leaf)) (Node 7 (Node 3 Leaf Leaf)(Node 2 Leaf Leaf))

atree = Node 4 (Node 2 (Node 1 Leaf Leaf)(Node 3 Leaf Leaf)) (Node 6 (Node 3 Leaf Leaf)(Node 7 Leaf Leaf))


get :: (Tree Int) -> Int
get Leaf = 0
get (Node a le ri) = a

instance == (Tree Int)
where
	(==) (Node a le re) (Node b le2 re2) = sum [a, get(le), get(re)] == sum [b, get(le2), get(re2)]
	(==) _ _ = True
	
instance < (Tree Int)
where
	(<) (Node a le re) (Node b le2 re2) = sum [a, get(le), get(re)] > sum [b, get(le2), get(re2)]
	(<) _ _ = True



sortTree :: [(Tree Int)] -> [(Tree Int)]
sortTree list = sort list

//Start = sortTree [btree, ctree, atree] // [(Node 4 (Node 2 (Node 1 Leaf Leaf) (Node 3 Leaf Leaf)) (Node 6 (Node 3 Leaf Leaf) (Node 7 Leaf Leaf))),
											//(Node 4 (Node 2 (Node 1 Leaf Leaf) (Node 3 Leaf Leaf)) (Node 6 (Node 5 Leaf Leaf) (Node 7 Leaf Leaf))),
											//(Node 1 (Node 2 (Node 8 Leaf Leaf) (Node 9 (Node 4 (Node 16 Leaf Leaf) Leaf) Leaf)) (Node 7 (Node 3 Leaf Leaf) (Node 2 Leaf Leaf)))]

Start = sortTree [Leaf, btree] 