Programming Languages (BSc, 18) Java, 7th lab:
---------------------------------------------
Task 1:
-------
a)Create a power() function for calculating power of natural numbers (both power base and exponent are natural numbers). 
The return type shall be double. For now define 0 raised to the power of 0 to be 1. Test the power() method with white-box testing.

b)
Modify power() so that it should be able to calculate powers with negative integer exponents.

Let's try if the unit test written in a are still passing.
Add unit tests for testing the new functionality.

compile and run commands:
------------------------
javac -cp .;junit-platform-console-standalone-1.9.1.jar MathUtils.java MathUtilsTest.java
java -jar junit-platform-console-standalone-1.9.1.jar -cp . -c MathUtilsTest

Task 2:
-------
The Book class represents an item (a book) at an auction.

The class contains a nested enumeration type (Book.Genre), which contains the following values: FANTASY, SATIRE, SCIFI, PHILOSOPHY, EDUCATIONAL.

The class has 5 private fields.

author (String)
title (String)
reserve price (int)
identifier (int)
genre (Book.Genre).
The class has a private constructor: it takes as parameter the author, the title, the genre and the reserve price, and sets the corresponding fields. The identifier should be initialized to a value which is larger by one than the previously assigned identifier. (The first identifier should be 0.)

The class contains a static make() method. This method takes almost the same parameters as the constructor. The only difference is that all the parameters are of type (String). The make() method checks that the parameters are valid and meaningful. In the positive case, it constructs and returns a new Book object, otherwise it returns a null reference.

The name of the author and the title are accepted, if they are not null, they contain at least two characters, and they only contain letters, digits and spaces.
The reserve price should be a positive value.
The genre should be convertible into a Book.Genre value.
Create a static method isSameGenre(), which takes two Book objects as parameter and returns whether they have the same genre.

Create a compare() instance method, which takes another Book object as parameter. This method can only compare books from the same genre - if called with books of different genres, the method should throw an IllegalArgumentException. When two books of the same genre are compared, they are compared based on the reserve price: the larger the reserve price, the "larger" the book is. If the current book is larger than the one passed as parameter, the compare() method should return 1; if smaller, it should return -1; and if equal, it should return 0.

Test the Book class with white-box testing. Try to maximize the following metrics.

coverage of methods
coverage of branches (both branches of each decision point)
coverage of conditions (subconditions in boolean expressions)
coverage of loops (execution of loop bodies 0, 1, 2 times)

Task 3:
------
The Adder class (under Files/) has an add() static method with two parameters representing numbers, and it returns their sum. For some reason, the type of the parameters and the return type are Strings. Therefore, numbers must be encoded to strings before calling this method, and the result should be also decoded. If the parameter strings cannot be interpreted as numbers, the method should throw IllegalArgumentException.

public class Adder {
    public static String add(String a, String b){...}
}
Test the add() method with black-box testing, taking care of the following.

the correct implementation of addition;
the algebraic properties of addition: commutativity, associativity, unit value;
for floating point numbers, precision up to 0.01;
ability to accept numbers in radix 2;
ability to accept numbers written in English;
invalid parameters (null or non-numbers) result in IllegalArgumentException
ability to ignore spaces at the beginning and at the end of the strings.