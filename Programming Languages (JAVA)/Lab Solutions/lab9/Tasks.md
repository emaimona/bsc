Programming Languages (BSc, 18) Java, 9th lab
Task 1:
-------
Create a divisors function which takes a positive integer as parameters and returns its divisors in a list data structure.

Task 2:
-------
Write a method named getStrSameBeginningAndEnding() which loops through in an ArrayList of strings (received as a parameter). It should return an ArrayList of strings, whose aren't empty and the first and the last letter is the same.

Write a method named removeStrDifferBeginningAndEnding() which deletes those strings from the ArrayList whose are empty or the first and the last letter differ. Instead of foreach loop use the ArrayList's removeIf() method, pass a proper lambda expression.

Task 3:
------
Write a method named minToFront() which gets an ArrayList of integers as parameter. The method should move the minimal element to the front of the list, preserving the other element order. For example, for the input [4, 65, 45, 44, 76, 2, 98, 72] the desired ouput is [2, 4, 65, 45, 44, 76, 98, 72]. For the minimal use Collections.min(). If the ArrayList is empty, the method should throw IllegalArgumentException.

Task 4:
------
Write MultiSet class representing a set of string with multiplicity: a set storing strings; the same string can appear more, so we store the number of instances for each string (multiplicity).

Use the Java's HashMap data structure where keys are strings, values are multiplicities.

Write a parameterless ctor, and other ctor getting an initial HashMap as parameter and copies it. Write a getData() method returning the HashMap data structure representation. Take care do not let the internal state out from the object.

Write a method named put() for adding a string to the set.

Write a method named intersect() which gets a MultiSet other reference as parameter and calculates the intersect of the current and the other MultiSet (the intersect should contain the elements that are present in both sets with the minimal multiplicity). The method should not modify the current instance; the result should be the reference of a newly constructed MultiSet.

Exercise 1:
-----------
Make a data structure representing a list of whole numbers, and call it IntList.

a) Implement an IntList with an array.

It stores these fields:

currentSize: int
maxSize: int
array: int[]
The constructor gets the max size as a parameter.

The class proivdes the following methods:

add() takes an int item and stores it in our list.
concat() takes another IntList instance and adds it's contents to the end of this list, provided this list has sufficent capacity. If the current list doesn't have enough capacity, throw an IllegalStateException.

removeItemsGreaterThan() takes an int (limit), and removes every element that's greater than the limit.

Override toString() to show a comma-separated list of numbers found in our IntList. If the list is empty print 'empty'.
