Programming Languages (BSc, 18) Java, 1st lab

Task 0
Find the home page of the course. Discuss how evaluation will happen. Check Canvas. Homework: study the home page.

Task 1
Create the shortest possible compilation unit in Java.

class A{}
Compile it using the javac command!

javac A.java
Check the generated .class file! Open this file with a text editor. As you can see, it's a binary file, but you can observe some meaningful identifiers in it.

Task 2
Create the Java program which does not do anything! For this, an empty main program is required. This is the shortest possible program in Java. (Well, you could use shorter identifiers instead of Skip and args, and you could remove some whitespaces still.)

class Skip {
    public static void main( String[] args ){
    }
}
Compile this class and run the program!

javac Skip.java
java Skip

Task 3
Create a program which reads the name of the user from the console, and then greets the user. You can use the following two commands:

System.console().readLine()
System.console().printf(...)

Task 4
Create a program similar to the previous one, but this time the name of the user should be provided as the first command-line argument! Printing to the standard output is also possible using the following command, which Java programmers usually prefer.

System.out.println(...)

Task 5
The program below should print the half of the numbers 1, 2, 3 and 4. The expected output is:
--------------------------
0.5
1.0
1.5
2.0
Altogether 4 numbers are printed!
-------------------
However, the program fails to work. Fix it!

class Print {
    public static void main() {
        for( int i = 1; i < 4; i++ ) {
            System.out.Println(i/2);
        }
        i = 4;
        System.out.println("Altogether " + i + " numbers are printed!")
    }
}

Task 6
Create a program which inputs two integer numbers, and for each integer number in the range defined by these two integers, it outputs the half of those numbers. To convert a string (provided as input) into an integer number, you can use the following conversion function:

Integer.parseInt(...)

Task 7
Create a program which converts its first two command-line arguments into integer numbers, and computes their sum, difference, product, as well as the quotient and remainder of integer division. The integer division should not be performed when the second number is zero. The results should be printed on the standard output. The program should print an error message if less than two command-line arguments were provided. The error message should be printed on the standard error (System.err) stream.

Task 8
Implement a program which computes the factorial of a given natural number.