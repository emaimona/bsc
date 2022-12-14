# Programming Languages (BSc, 18) Java, 3rd lab

### Task 1

Reorganize the code of class `Point` and the corresponding main program
as produced in the previous lab. In the reorganized code, those classes
should go to the `point2d` package. Ensure that the `Point` class is
not visible from outside of its package. The `Point` class and the
main program should be written as two compilation units.

javac point2d\Point.java point2d\MainPoint.java
OR javac point2d\MainPoint.java
OR javac point2d\*.java
java point2d.MainPoint

### Task 2

Change the code produced in Task 2 in a way that the main program goes
into different package, `pointm`.

javac point2d\Point.java pointm\MainPoint.java
java pointm.MainPoint 

### Task 3

#### a

Create a `Circle` class to represent a circle. A circle has a center (`x`, `y`
are `double`, initialise to 0), and a `radius` (also `double`, initialise to 1).
Write a `getArea()` method returing the area of the circle. Create an instance of
the `Circle` class, write its area to the screen, set the center to (5, 2),
radius 10, then write again its area to the screen.

#### b

Modify the code for task **a** in such a way that the data fields are only
accessible via a getter/setter. Throw `IllegalArgumentException` if the radius
would be 0 or negative.

#### c

Modify the code for task **b** in such a way that the data fields are initialised by a constructor.

### Task 4
#### a
Create a package `circle` and its sub-package `utils`. Class `Point` should
now be put into this `circle.utils` package. Create the `circle.Circle`
class, which stores the radius of the circle (`double`) and the center of
the circle (`x`, `y` fields).

Write a `getCenter()` method for `circle.Circle` returning the center as
`circle.utils.Point`.
Create a main program as class `circle.Main`.

javac circle\utils\Point.java circle\Circle.java circle\MainCircle.java
OR javac circle\MainCircle.java
java circle.MainCircle

#### b

Modify the code for task **a** in such a way that `circle.utils.Point` use
constructors instead of setters. // classwork

### Task 5

Create a class `stringutils.IterLetter`. Its constructor expects a `String`
reference. (Make sure that your code handles the case when this reference
is `null`). Create the method `hasNext()`, which returns `true` if (and only if)
there are letters to be printed in the string. Create a method `printNext()` in this class, which prints the
next unprinted letter of the initialising string in a new line on the
standard output. (The first call of the method prints the first letter,
the second call prints the second letter, and so on). 

After all the letters of the string have been printed, the `printNext()`
method should not print anything anymore.

The class should have a `restart()` method, which can be used to
re-initiate the printing functionality. After `restart()`, the
`stringutils.IterLetter` object should print the first letter of the
initialising string for the following `printNext()` method.

Create a main program in `Main` in the anonymous package. The main program
should instantiate class `stringutils.IterLetter`, and illustrates its
use.

Exercise 1:
-----------
Create a class `roo.kangaroo` representing kangaroos. This class should have two fields: one represents the name `String` and the other the age `int` of the animal.

The constructor of the class takes two parameters, corresponding to the two fields. The class should contain a method display `String`, which takes the name of a country as parameter, and does the following: it prints the name of the kangaroo, as well as the name of the country; then it increases the age of the kangaroo by one, and prints the new age.