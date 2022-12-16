module PT8
import StdEnv


// Name Maimona Emanuel Nzinga
// Neptun GAU5OE
/*
	Define a class called "Plus" of any type and define the binary operator ++++ for integer type which will 
														add the operands if both are even and 
														subtract them if both odd, 
														otherwise, don't do anything, results 0.
*/

class Plus a
where
	(++++) infix  4 :: !a !a ->	Int
	

instance Plus Int
where
	(++++) a b
	| isEven a && isEven b = a + b
	| isOdd a && isOdd b = a - b
	= 0

//Start = 5 ++++ 3	// 2
//Start = 5 ++++ 4	// 0
Start = 6 ++++ 4	// 10
//Start = -4 ++++ 6   // 2
//Start = -4 ++++ -5  // 0
//Start = -3 ++++ -7	// 4