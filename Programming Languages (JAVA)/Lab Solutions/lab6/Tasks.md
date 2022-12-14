# Programming Languages (BSc, 18) Java, 6th lab

### Task 1

#### a

Modify the solution of **Task 7** of the **1st lab** so that operands have type `double` and the operations to be performed are provided as command line arguments. No need to extend the set of supported operations.

In case the program is called with insufficient number of arguments, it shall throw an `IllegalArgumentException` in its `main()` method. Throw an `ArithmeticException` in case of diving by zero and, in case of an unsupported arithmetic operation also throw an `IllegalArgumentException`.

#### b

Modify **a** so that exceptions are caught in `main()` and appropriate error messages are printed to the console instead (eg. `"Invalid program`
`arguments provided."`, in case of a missing argument). Also catch the exception thrown by `parseDouble()` in case of an invalid string.

#### c

Modify **b** so that each exception thrown by you is provided with an appropriate error message in its constructor. When catching these exceptions print **these** messages to the console.

### Task 2

#### a

We have an input file containing integer numbers separated by commas. Your task is to calculate the **sum** of values in each line and print result (lines of sums) to the screen.

```
1,2,5,-2    
10,20,0,7   
3,2
2
0
1,2
3
```

Use `BufferedReader` in your solution!
Look for a method in the `String` class that is capable of splitting a line around some special character (comma, in our case)! split()

We can assume the input file's format is always valid.

#### b
Modify **a** so that results are printed to another file instead of the screen.

### Task 3:
------------
Look up some string in a text file! The file name is provided as command line argument, the string should be read from the console.

Print the number of lines containing an occurrence of the string to the console!

Partial matches also count. That is, the line can contain other text beside our string and still count as an occurrence. (Try finding a relevant method in the `String` class!)

hello
__hello2
hello
	hello
	
				hello


 Scanner class to get user input

### Task 4:
-----------
In this task modify **lab03/task 4/b**.

#### a

Create a `static` method in the `Circle` class called `readFromFile()` which loads the data of a circle from a filename (provided as parameter). The file should contain the coordinates *x* and *y*, and the *radius*, all separated by newlines. The method shall construct a `Circle` object using these data and return its reference. Any exception that can arise during these operations should be handled by the caller.

Create a method called `saveToFile()` in the `Circle` class that saves the current `Circle` object to the filename (provided as parameter). Exceptions during file operations should not be handled in the method. However, exceptions during write operation must not result in the loss of already written data, therefore make sure the `Writer` object is properly closed!

Let's try what's the difference if we catch/do not catch exceptions raised by the called methods.

notes:
there are 3 ways to read console input
BufferedReader, Scanner, and System.console() classes