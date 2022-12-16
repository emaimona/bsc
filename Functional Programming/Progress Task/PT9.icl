module PT9
import StdEnv

// Maimona Emanuel Nzinga
// GAU5OE

:: Tree a = Node a (Tree a) (Tree a) 
          | Leaf
          
tree1 = Node 2 (Node 5 (Node 3 (Node 24 Leaf Leaf) Leaf) (Node 6 Leaf (Node 7 Leaf Leaf))) (Node 8 (Node 15 Leaf (Node 10 Leaf (Node 14 Leaf Leaf))) (Node 13 Leaf (Node 16 Leaf Leaf)))
treeOne = Node 10 (Node 8 (Node 4 (Node 3 Leaf Leaf) Leaf) (Node 7 Leaf Leaf)) (Node 7 (Node 6 Leaf Leaf) (Node 5 Leaf (Node 4 Leaf Leaf)))
treeTwo = Node 10 (Node 2 (Node 4 (Node 9 Leaf Leaf) Leaf) (Node 7 Leaf Leaf)) Leaf

/*
	Given an Int tree and a boolean function and count the node that returns true when the node value is passed into boolean function.
*/

nodeCountBy:: (Tree Int) (Int -> Bool) -> Int
nodeCountBy Leaf f = 0
nodeCountBy (Node a le ri) f
| f a = 1 + (nodeCountBy le f) + (nodeCountBy ri f)
= (nodeCountBy le f) + (nodeCountBy ri f)

//Start = nodeCountBy tree1 isOdd // 5
//Start = nodeCountBy treeOne isEven // 5
//Start = nodeCountBy treeTwo isEven // 3

/***************************************************************************************************************************************************************************************/

::Movie = {
			title::String,
			casts::[Cast],
			year::Int,
			rating::Real,
			country::String
			}
::Gender = Male | Female
::Cast = {
			name::String,
			gender::Gender
			}

cast1 = { name="Jackie Chan", gender= Male}
cast2 = { name="Jet Li", gender= Male }
cast3 = { name="Millie Bobby Brown", gender=Female}
cast4 = { name="Chris Hemsworth", gender=Male }
cast5 = { name="Zendaya", gender=Female }
cast6 = { name="Emma Stone", gender=Female }
cast7 = { name="Emma Watson", gender = Female }
cast8 = { name="Sandra Bullock", gender = Female}
cast9 = { name="Chris Evans", gender= Male}
cast10 = { name="Tom Holland", gender=Male}
cast11 = { name="Tobey Maguire", gender=Male}
cast12 = { name="Bae Suzy", gender=Female}
cast13 = { name="Park Seo Joon", gender=Male}

movie1 = { title="MOVIE I.", casts=[cast1, cast6, cast10], year=2019, rating=8.5, country="USA"}
movie2 = { title="MOVIE II.", casts=[cast4, cast8, cast7], year=2020, rating=8.0, country="Spain"}
movie3 = { title="MOVIE III.", casts=[cast13, cast12, cast9], year=2019, rating=9.0, country="Korea"}
movie4 = { title="MOVIE IV.", casts=[cast3, cast11, cast8], year=2021, rating=6.5, country="India"}
movie5 = { title="MOVIE V.", casts=[cast2, cast4, cast10], year=2022, rating=7.4, country="Hungary"}
movie6 = { title="MOVIE VI.", casts=[cast3, cast5, cast8], year=2022, rating=7.4, country="Hungary"}


movieList = [movie1,movie2,movie3,movie4,movie5, movie6]

/*
 2. Find the average rating of the given movie list
 
*/

movieMaxRating:: [Movie] -> Real
movieMaxRating lis = avg [ x.rating \\ x<-lis ]


Start = movieMaxRating movieList // 7.8





