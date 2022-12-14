# Programming Languages (BSc, 18) Java, 11th lab

### Task 1

Modify the 1st task of 8th lab as the followings. The `Book` object should be constructible only in it's descendant classes, further the 'Book' class should guarantee that the descendant classes' interface have at least the followings: constructor, `getShortName()`, `toString()`, `getPrice()`, `createReference()`.

The `getPrice()` belongs to the `Book` class, but without implemntation. The class should be  abstract; the `Book` class implements the following methods:

- `getShortName()`
- `toString()`

The `Book` class doesn't implement the following methods (these implementations should be in the descendant classes):

- `getPrice()`
- `createReference(String, int, int)`

### Task 2

This Java program consists of several classes, these classes beside others should guarantee two properties. The state of an object is reversible, if it has a `reverse()` method, that sets the object's internal state as it was before the last `set` call was called. For example, we have a representation of a point (`ReversablePoint`), that containing the `x` and `y` data members with the value `(2, 3)`, then calling a setter (`setX(10)`) followed by the `reverse()` method, we should as again have the `(2, 3)` as the x, y values.

The printable property means that the class has a `print()` method, which prints the internal state of the class the screen. Of course, the class can have both properties too (`PrintableAndReverseablePoint`).

#### a

Make an `interface` with the name `Reversable`, that contains a `reverse()` method which parameterless and has no return value. Write the `ReversablePoint` class, that illustrate a point as two integers (x, y) and implements the `Reversable` `interface`.

Make an `interface` with the name `Printable`, that contains a `print()` method which parameterless and has no return value. Write the `PrintablePoint` class, that illustrate a point as two integers (x, y) and implements the `Reversable` `interface` (this step could be skipped and this code could be right away extracted into a `Point` superclass, as in task B). Write the `Book` class which implements the `Printable` `interface` too. A book has an author, a title and a constructor. Write the `foo()` static method in the main program, that accept printable objects and calls there `print()` method.

Write a `PrintableAndReverseablePoint` class, that implements the `Printable` and the `Reversable` `interfaces`.

Is it possible to make a class hierarchy like this with abstract classes?

#### b

Modify the solution of task (B), so that extract the common code from the `ReversablePoint`, `PrintablePoint` and `PrintableAndReverseablePoint` classes into a `Point` superclass (x, y data members, constructor, getters, setters). The descendant classes should override the superclass' setter methods, besides others, they call the superclass' setter methods.

#### c

Organize every classes and interfaces into separate Java translation units.


### Exercise 1

Make an abstract `Prism` class, that illustrate prisms. Store the prism's height, and make an abstract (or descendant) method which calculate the base area of the prism (`baseArea()`). With the help of this method make a second that calculates the prism volume (`volume()`). Move the `Prism` class into the `polyhedra` package! From the `Prism` descend the `Cylinder` class which represents cylinders and the `Cube` class which represents cubes!

Beside overriding the abstract methods, override the `toString()` method as well, so that it should return a proper string representation of the current class.

at the `Cylinder` class:  
`Cylinder : (h=10 , r=5)`

at the `Cube` class:  
`Cube : (h=4)`

These classes should be in the `polyhedra` package!

### Exercise 2

Make an `interface` with the name `Shape`, that contains the signatures of two methods: `getPerimeter()`, `getArea()`.

Write the `Square`, the `Rectangle` and the `Circle` classes that's represents a square, a rectangle and a circle and implements the `Shape` `interface`.