Programming Languages (BSc, 18) Java, 10th lab

Task 1:
-------
We are going to enhance the first task of the 8th lab.

Write a getter method for the pages field of the Book class (getPages()).

Create an Article class, that represents some kind of article (e.g. article, review, recommendation). As we have seen in Lab 8 these articles can reference books and these are collected in a reference collection. In this task we are creating such a reference collection and we are not concerned about the rest of the Article class.

An article possesses a title, a body, a conclusion (title, body, conclusion, all strings), a PrintWriter and an ArrayList capable of holding Book references (refs). Write a constructor that initializes the fields of the Article.

Create an addBookToReferences() method, that adds the passed Book parameter to refs.

Write a print() method, that writes the content of a finished article into a file. The name of the file is passed as a parameter. Write the title, body, conclusion and the references of the books (createReference()). Create a private helper method, that writes the reference of the book to a file where the title is the title of the current article, the starting pages is 1, and the final page is the last page of the book (getPages()).

How would you implement the program without overriding methods? What are the drawbacks of such a solution compated to the one using method overriding?

Task 2:
-------
Create a generic Bag<T> class representing a bag. A bag is a set that may contain duplicates of it's elements.

Add a HashMap<T, Integer> datamember to it which will be initialized by a parameterless constructor. Add an add(T element) method to it. This will check if the key is already present in the bag: if it's not, add it with value 1, otherwise get it's current value and increment it by 1. (The map will track how many instances of each element is in the bag.)

Add a countOf(T element) method to it returning an int that returns how many duplicates of the element is in the bag. If there is no such key in the bag, return 0.

Add a remove(T element) method for removing an element. This will decrement the value of the given key by 1 in the bag. If the value drops to 0, remove the corresponding key-value pair from the map so that no superfluous data is stored. If the element was not in the bag throw a NotInBagException exception which is a user defined exception class. The NotInBagException exception inherits from Exception and it's constructor expecting a string parameter should call the super class' constructor.

Create a main program which will process an input text file containing a word in each line and counts how many times each word appeared in the input file using the Bag<T> class.

input.txt:

hello
world
interface
abstract
abstract
world
world
world
hello
world
X-Files
protected
abstract
abstract
extends
protected
socket
world
hello
socket
extends

Task 3:
-------
Write a generic method to exchange the positions of two different elements in an array.

Exercise 1:
----------
Create a generic CheckedSet<T> class representing a set. Add a HashSet<T> datamember to it which is initialized by a parameterless constructor. Add a method for getting the current size of the set. Add an add(T element) method that may throw an AlreadyContainedException checked exception. Create such a user-defined exception class that is thrown when the set already contains the given element; otherwise add the element to the set. Add a contains(T element) method returning a boolean that checks if the set contains the given element. Test the new class in a main program.