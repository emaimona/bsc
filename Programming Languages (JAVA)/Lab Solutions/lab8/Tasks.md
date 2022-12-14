Programming Languages (BSc, 18) Java, 8th lab:

Task 1:
-------
a) Create a Book class representing a book. A Book has three fields: 
author (String), title (String), and pageCount (int). Create a PrintedBook
 and an EBook class extending from Book. A book's author and the title should only be accessible to Book, while pageCount should be accessible to its subclasses.

The Book class has two constructors:

A constructor that takes the author, title, and pageCount as parameters 
and sets the corresponding fields. Make sure that the length of author is 
at least two, while the title's length is four or greater. If either one is 
incorrect, throw an IllegalArgumentException

A constructor that takes no arguments. It calls the previously defined 
ctor with the following values:

author: John Steinbeck
title: Of Mice and Men
pageCount: 107

Add a getShortName method to Book, that returns a string composed of the 
first two chars of the author, first four chars of the title, and the 
pageCount.

Write a main class that constructs two Books, one with each constructor, 
then prints their short names (getShortName) to the console.

b)
A printed book can have two cover types: Softcover and Hardcover. Create an 
enum to store these values. The PrintedBook class stores it's cover type in
 a field.

A PrintedBook must be constructible with and without parameters.

Without parameters: call the superclass's parameterless constructor, set 
the coverType to Hardcover, and add six to pageCount to account for the 
additional pages added in print.
With parameters: take all four fields and set them. (author, title, 
pageCount, coverType)
The EBook class stores its fileSize in an int field. An EBook instance 
can only be constructed by providing these parameters: author, title, 
pageCount, fileSize.

Add a getPrice method to PrintedBook, and EBook, it calculates the books
 price in the following way:

For Softcover printed books the price is equal to: pageCount * 2
For Hardcover printed books the price is equal to: pageCount * 3
For EBooks the price is equal to: pageCount + fileSize
In Main instantiate PrintedBook and EBook. Print their short names and 
prices.

c)
Add a toString method to the Book class. It returns the book's 
author, title and page count. For EBooks, this toString is sufficient. 
PrintedBook should override this method by extending its parents toString
 with its coverType.

Books often get referenced in articles for these use cases you need to 
create a reference catalog. Depending on the book type, it includes author,
 title, and the cited pages.

Add a createReference method to Book. createReference takes an article's 
title (String) and a start and end page for the citation, and returns a 
string reference pointing to a book.

The reference's format is as follows: "getShortName() [start page - end page] 
referenced by article: <article title> "

For printed books and e-books, the formatting is different. Override 
createReference in PrintedBook and EBook.

For printed book the format is: "super class's toString() 
[start page - end page] referenced by article: <article title> "

For digital books the reference format is: "super class's toString()
 (File size: <file size>) [start page - end page] referenced by article: 
 <article title>"

When using digital source materials, it's a good idea to indicate the date
 of use. Overload the EBook class' createReference method. 
 This new createReferece should take an article's title and the date of 
 use. It returns a reference in this format: "super class's toString() 
 (File size: <file size>) referenced by article: <article title>, file's
  use date: <date of use>"