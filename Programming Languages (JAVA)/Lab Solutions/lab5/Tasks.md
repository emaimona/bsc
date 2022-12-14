Programming Languages (BSc, 18) Java, 5th lab
Task 1:
-------
Create the class IntegerMatrix with the following operations.

A constructor expecting three arguments:
int rowNum (number of rows in the matrix);
int colNum (number of columns in the matrix);
int[] linearData (an array storing the elements of the matrix in a row-major manner, i.e. {1,2,3,4,5,6) for the
2×3
matrix below).
[142536]
A toString() method, which produces a character string from the matrix elements, separating rows with semicolon (;), and elements within a row with comma (,). The string representing the matrix above is: "1,2,3;4,5,6".

Task 2:
-------
Create the WildAnimal enum in the WildAnimal.java file, it should contain four values: monkey, elephant, giraffe and racoon.

These animals get two values in their constructors, which fruit do they like and the ideal portion for a day of that fruit.

Create the listAllAnimals() method, which returns a string like this:

"animal ordinal: name of the animal desires eating name of the fruit a week."

For example, elephants like to eat 30 portions of raspberries a day:

"2: ELEPHANT desires eating 210 raspberries a week."

The enum should be iterated using the values() , it's ordinal by the ordinal() methods.

Create a toString() method, which returns the informations stored by the specific enum value.

Try and test your enum and the methods in a Main class.

Task 3:
-------
Write Javadoc comments to Task 1 functions. Use at least the followings:

@param
@return
Create documentation for the class as well. It should contain the @author , @version and @since tags.

Generate HTML documentation for your program with the javadoc tool!

Task 4:
-------
Correct the errors in the program code below.

Create the IntVector class in package util, which represents a sequence of integer numbers! The class should have a field of type integer array, this will store the elements of the sequence. The class should have a constructor, which takes an array of integer numbers and initializes the IntVector with these numbers (the constructor should copy its content).

Add a method named add(int n), which adds n to each element of the sequence! Prepare a toString() method producing a character string. This method should enumerate the elements of the sequence in brackets, separating consecutive elements with a space (for example: [1 2 3]).

util/IntVector.java:

package util;

public class IntVector {
    int[] numbers;

    IntVector(int[] numbers) {
        numbers = numbers;
    }

    public void add(int n) {
        for (int i = 0; i < numbers.length-1; i++)
            numbers[i] += n;
    }

    public String toString() {
        return Arrays.toString(numbers);
    }
}
IntVectorDemo.java:

class IntVectorDemo {
    public static void main(String[] args) {
        int[] ns = new int{1,2,3};
        IntVector v = new IntVector(ns);
        IntVector v2 = new IntVector(ns);

        System.out.println(new int{1,2,3});
        System.out.println(v);
        System.out.println(v2);

        System.out.println("v.add(1);");
        v.add(1);
        System.out.println(v);
        System.out.println(v2);

        System.out.println("ns[0] = 10;");
        ns[0] = 10;             
        System.out.println(v);
        System.out.println(v2);
    }
}