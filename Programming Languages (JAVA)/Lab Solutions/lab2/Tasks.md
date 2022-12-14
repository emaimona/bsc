Programming Languages (BSc, 18) Java, 2nd lab
-------------------------------------------------
Task 1:
Create a Point class containing two fields(variables), x and y of type double. Create a method move(dx,dy) which can translate a point with coordinates dx and dy. Create a method mirror(cx,cy) which can reflect a point through the coordinates cx and cy.

Create a PointMain program to test the use of the Point class.

Task 2:
Rewrite the mirror method in class Point in such a way that it has a single parameter of type Point, representing the point through which the reflexion should be performed.

Create a distance(p) method, which computes the distance of a point from the point p (provided as parameter). Use the Math.sqrt(...) function and the Pythagorean theorem.

Update the PointMain class to test the new operations!

Task 3
Implement the Complex class representing complex numbers with a real and imaginary component. The class should contain fields re and im of type double. Create a method abs() which computes the absolute value of the complex number.

Implement the add(c) and sub(c) and mul(c) methods, which, respectively, add another complex number c to a complex number, subtract c from the complex number and multiply the complex number with c. These methods should be used as, and should behave like, illustrated below.

alpha.re = 3
alpha.im = 2   // 3 + 2 i
beta.re = 1
beta.im = 2  //1 + 2 i
alpha.add(beta)
// alpha.re == 4 && alpha.im == 4 && beta.re == 1 && beta.im == 2

How to find the absolute value of a complex number?
https://www.varsitytutors.com/hotmath/hotmath_help/topics/absolute-value-complex-number

addition, subtraction, and multiplication in complex numbers

Task 4:
Create a class Circle representing circles with an origin (fields x and y of type double) and a radius (field of type double). Create a method enlarge(f), which multiplies the radius with f, enlarging the circle with a factor f (or shrinking if f is smaller than 1). Create a method getArea() which computes the area of the circle. Use the constant Math.PI!

Task 5:
Write the Distance program, which interprets its command line arguments as a sequence of points, and sums up the distances found between any two consecutive points (i.e. the length of a polygonal chain, or polyline). The first two command line arguments represent the x and y coordinates of the first point, then the third and fourth command line arguments represent the second point, and so on. We can assume that the number of command line arguments is even, and each command line argument is an integer number.

The program should work by using the Point class and its distance method. For example, if the six coordinates of three points are provided as command line arguments, the program should compute the distance between the first two points, as well as the distance of the last two points, and print the sum of these two distances.

Examples:

> java Distance
0.0
> java Distance 1 2
0.0
> java Distance 0 0 3 4
5.0
> java Distance 1 2 4 6
5.0
> java Distance 1 2 4 6 7 6
8.0