% Programming languages (Java) midterm exam retake, 11/11/16

# General information

Below you could find the description of required classes and their
methods. You could always add private auxiliary methods to your
classes. Do your best in order to hide the internal representation of
your classes. Follow the visibility specifications of the description.

Your program has to compile with the given tests. 

[Java API
documentation](https:), a
blank sheet of paper and a pen are allowed to use. If you have any
question, remark, please tell to the supervisor and *NOT* to your
fellow students.

# Testing

compile and run commands:
------------------------


# Synopsis

In this exercise we will implement a car rental service.

For your program you could find a [tester] with a sample
file, so you could test your program during the exam.

# Detailed description

## `rental.Car` *(14 points)*

Create the public `rental.Car` class. The fields and methods are
as follows.

  - A `String` licensePlate and an `int` price. These fields are
    hidden. *(1 point)*

  - A public constructor which takes the license plate and the price
    as arguments, and initializes the fields. *(1 point)*

  - A public no-argument `getPrice()` which returns the price of the
    car. *(1 point)*

  - A public no-argument `getLicensePlate()` which returns the license
    plate of the car. *(1 point)*

  - A public no-argument `toString()` which returns the string
    representation of the car. The result should look like
    `Car(DEF123,500)` for a car with license plate `DEF123` and price
    of 500 (euros). *(2 points)*

  - A public `isCheaperThan()` which takes a car as argument and
    returns `true` if the current car (on which the method is invoked)
    is cheaper than the argument car. Otherwise the method returns
    `false`. *(1 point)*

  - A public class-level `make()` which takes the data of a car as a
    single string and returns a new car. The argument should look like
    `DEF123:500`, but it has to be validated. *(5 points)*

      a. The string must consist of two parts: license plate and
         price, separated with a colon.

      #. The license plate must consist of 6 characters.

      #. The price must be an integer.

      #. The price must be positive.

    To check that the price is in fact an integer, you could choose
    from two options.

      a. Catch the [`java.lang.NumberFormatException`]exception
         thrown by [`Integer.parseInt()`] when the
         conversion from string fails.

  - A public class-level `CAR_OF_THE_YEAR` field with type of
    `Car`. The license plate is `ABC123` and the price is 500. *(2
    points)*

## `rental.CarRental`  *(17 points)*

Create the public `rental.CarRental` class. The fields and methods are
as follows.

  - A `String` name and a `cars` which is
    [`java.util.ArrayList`] of cars for rent. These fields
    are hidden. *(2 points)*

  - A public constructor which takes the name of the rental service
    and a string filename as arguments. The constructor initializes
    the fields and creates the cars from the file. A car may only be
    created from a line when it meets the requirements above. Do not
    add `null`s to the list.

    You may use a [`java.util.Scanner`]object to read the
    contents of the file.

    A [`java.io.FileNotFoundException`] may be thrown when the
    file is not found. In this case the `cars` list has to be
    initialized as an empty list and the exception has to be
    catched. *(5 points)*

  - A public no-argument `toString()` method which returns the string
    representation of the rental service. It should look like
    `CarRental(Fix It Yourself Car Rental, [Car(ABC123,400),
    Car(DEF452,600)])` for a service named `Fix It Yourself Car
    Rental` with two cars for rent.

    You may use the `toString()` method of the
    [`java.util.ArrayList`]. *(2 points)*

  - A public no-argument `averagePrice()` which returns the average of
    prices of cars for rent. The method returns `-1` when there are no
    cars available for rent.  *(3 points)*

  - A public no-argument `rentCheapest()` which removes the cheapest
    car from the list and returns it. The method returns `null` when
    there are no cars available for rent.

    You may use one of the `remove()` methods of the
    [`java.util.ArrayList`]to remove a car from the list.
    *(5 points)*