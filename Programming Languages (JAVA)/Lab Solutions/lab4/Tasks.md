Programming Languages (BSc, 18) Java, 4th lab
----------------------------------------------
Task 1:
-------
a)
Create a Java program to find the item in the array {1.3, 5.2, 7.7, -2.3, 23.45} that is closest to the average of the array. In this solution you can use the fact that we are working with an array with size 5.

b)
Modify the a solution in such a way that the program asks from the user the content of the array. Firstly ask for how many values the user want to enter (store in N), then create an array with size N, and finally store a number of N values read from the user.

Task 2:
-------
a)
Create a toString() method for the Point class in lab03 task 4/b which returns a string containing the x and y coordinate in a (x,y) form.

Create a program which reads (from standard input) the coordinates of 3 Point objects, and instantiates three such objects, storing their references in an array.

Then the program should compute the center of mass of the points, and print out this point on the screen. (The coordinates of the center of mass is defined as the average of the corresponding coordinates of the original points.)

b)
Modify the a program in such a way that the computation of the center of mass is performed by a static method of the Point class. This method takes the input points in an array, and provides the result as a return value.

The program should ask the number of points to store.

c)
Modify the b program in such a way that every Point instance has an unique identifier number (id, integer). This numbering should start with 1. To achieve this, store in a static member in the Point class a counter, which should be incremented when a Point instanced. Modify the toString() method to contain the ID too.

Task 3:
-------
Draw a memory map of the following Java program for every lines marked with (1)-(5). After executing (5), which objects may be deleted by garbage collector?

Main.java:

class Foo {
    private int x;

    public Foo(int init_x) {
        x = init_x;
    }
}

public class Main {
    public static void main(String[] args) {
        int counter = 10;       // (1)

        Foo obj;                // (2)
        obj = new Foo(5);       // (3)

        Foo obj2 = new Foo(7);  // (4)
        obj2 = obj;             // (5)

        // ...
    }
}
Modify the constructor in Foo to it's parameter name should be x instead of init_x, use the this keyword to indicate x member field access.

Task 4:
-------
Let's organise Task 2/c solution into a mass package. The main class should be in mass package, the Point class should be in the mass.util package.

a)
Create a JAR archive file from the generated class files with name mass-deploy.jar. Run this Java program from the mass-deploy.jar archive with the java program. Specify the JAR's entry point with the -classpath option.


Instructions:
-------------
// Create JAR file containing mass/PointMain.class mass/util/Point.class
 jar -cf mass-deploy.jar mass/PointMain.class mass/util/Point.class


// Run JAR file with launching main class
java -classpath mass-deploy.jar mass.PointMain

// Extract JAR file (just to check its content)
jar xf mass-deploy.jar

b)
Create a manifest file to specify this program's entry point (mass.Main). Create a JAR archive which is able to run without specifying classpath. Run this Java program in JAR file with the java program -jar option.

// Create JAR file containing mass/Main.class mass/util/Point.class with manifest file META-INF/MANIFEST.MF
jar cmvf META-INF/MANIFEST.MF mass-deploy.jar mass/PointMain.class mass/util/Point.class

// Run JAR file
java -jar mass-deploy.jar