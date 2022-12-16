# Command line usage

1. Print the current directory (`pwd`).
2. List the files and folders in this directory (`ls`).
3. View the detailed information of files and directories. When and who created
   these (`ls -l`)?
4. What further flags does `ls` command have (`man ls`)?
5. Create a directory (`mkdir`).
6. Change to that created directory (`cd`). Check if the current directory
   is really changed. Step back to the parent directory (`cd ..`) and back to
   the created directory again.
7. Create a text file and print its content (`cat`). The command `cat` is the
   abbreviation of *concatenate*. How can the content of multiple files be
   printed after each other?
8. Copy the text file (`cp`) to the current directory and to the parent
   directory. Check if the copy operation has happened.
9. Rename the text file in the current directory (`mv`).
10. Remove the file (`rm`) and the directory (`rm -r`).
11. Print the number of lines, words and characters in a file (`wc`). Print the
    number of lines only. If you don't know what flag can do that then check it
    in the manual.
12. Create a program which prints `Hello World`. Pipe the output of this
    program to `wc`.
13. Create a few text files. Hide the word "apple" in one of them. Try to find
    which file contains this word with `grep`.
14. Let's create a multi-directory deep directory structure. Hide the file
    "apple.txt" somewhere. Try to find this file with `find` command.

# Standard I/O

1. Create a program that prints your name.
2. Create a program which prints the sum of two numbers.
3. Create a program in which you divide two numbers. Print the result. What
   happens if the divisor is 0? What happens if we use `int` or `flat`
   variables?
   - Use `%f` formatting character. Print the result with two decimals.
   - Use `%d` formatting character. Check what happens.
   - Use `-W`, `-Wall`, `-Wextra` and `-pedantic` flags. Does it result a
     compilation error when a wrong formatting character is used?
4. Create a program where you compute the area of a square and a circle. Get the
   length of the square and the radius of the circle from the user.
   - Use the function `scanf("%f", &a)`. Use the operator `&` which returns the
     address of a variable. The value of *pi* should be 3.1415.
5. Create a program which greets your name. Store your name in a variable.
   - Use the type `char[]` and `%s` formatting character. Pay attention on the
     usage of string type: `char name[32]`.

# Base types

1. Declare an `int` variable and print its value. Notice what the initial value
   of a variable is.
2. Assign a new value to the previous variable (it can be a constant value or
   can be read from the user with `scanf()`) and print if the value is even or
   odd.
3. Print if the number is positive or negative or zero.
4. Try to assign a floating point number, a char, a boolean and a string to the
   `int` variable. If the assignment is successful then print its value. Use
   `-W`, `-Wall`, and `-Wextra` flags during compilation.
5. Based on the previous example examine the conversion between all known base
   types. Can all types be converted to another? If yes, then what is the rule
   of conversion?
6. Determine the greatest and the smallest integer numbers (`sizeof`). Assign
   the greatest integer to a variable and add one. Check what happens.
7. Determine the average of two integers.

# Exercises 1

1. Create a Fahrenheit-Celsius converter (C = (F - 32) / 1.8). Write [-20; 200]
   interval Fahrenheit values with a scale of 10, and the corresponding degree
   Celsius.
2. Print the words `"Hello"` and `"World"` using `printf()` function. Put these
   two words between quotes in the output.
3. Create a program which gets an integer and reverses it. Use only arithmetic
   operations. E.g. 12345 -> 54321.
4. Determine the greatest common divisor of two integers. It can be
   brute-force, subtraction method, Euclidean-algorithm.
5. Write out a 10x10 times table. Separate the numbers in a line with tab
   characters.
6. Write the real numbers from 0 to 1 in increments of 0.1.
7. Draw an empty chessboard. Mark dark fields with `[]`, light fields and two
   spaces. Use divisibility by two.
8. Write out how many bytes your machine represents an `int`, `long int`,
   `unsigned int`, `unsigned long int`, `char`, `bool`, `float`, `double`,
   `long double` value.
9. Check if a number is a palindrome. Use only arithmetic operations for the
   solution. Eg: 12321 is a palindrome, but 12345 is not.
10. Determine whether two integers are amicable. Two integers are amicable if
    the sum of the divisors of one smaller than itself is equal to the other,
    and vice versa. E.g.: 220 and 284.
11. Determine whether a given number is prime. Write the primes up to 1000.
12. Earlier we listed the size in bytes of different basic types. Let's
    determine the same for pointers pointing to these types and arrays
    containing elements of this type.

# Exercises 2

1. Write out how many bytes your computer represents an `int`, `long int`,
   `unsigned int`, `unsigned long int`, `char`, `bool`, `float`, `double`,
   `long double` value.
2. Try operator chaining (a < b < c, a = b = c).
3. Declare an `int` variable. Calculate the largest value that can be stored in
   it. Give the variable this number as its value, then add one in a subsequent
   statement. Print the increased value.
4. Declare an `unsigned int` variable and repeat the steps of the previous
   exercise.
5. How many ways can you write 42 on the screen? Use signed, integer types and
   literals. You can use char type variable. No other operator can be used
   except for the value assignment. (Hint: octal, hex literals, type
   conversions, overflow)
6. Write a program that determines whether the number is a leap year from the
   standard input. A leap year is any year divisible by four, except those
   divisible by a hundred. However, those divisible by four hundred will also be
   leap years. (DO NOT use `if` in the solution!)
7. Read the characters `0-9`, `a`, `b`, `c`, `d`, `e`, `f`. Give an error
   message for everything else. Interpret the number as hexadecimal and convert
   it to base 10. Use character to digit conversion.
8. Check some undefined behaviors of C programs:
   [Github list](https://gist.github.com/Earnestly/7c903f481ff9d29a3dd1)
9. Draw the first *n* lines of Pascal-triangle. Read *b* from the user.
10. Do some research about bitwise operations and their usage:
    https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/

# Arrays

1. Create a program which fills up an array with zeros.
2. Create a program which adds up the integers of an array.
3. Create a program which prints the greatest element of an array.
4. Create a program which prints the lowest element of an array.
5. Create a program which calculates the weighted sum of an array. The weights
   are listed in another array. For example: first array: [1, 2, 3, 4, 5],
   second array: [1, 1, 2, 3, 5]. Weighted sum: 1*1 + 1*2 + 2*3 + 3*4 + 5*5.
6. Calculate the average of some floating point numbers in an array.
7. Create a program which gets two strings and input and determines which one
   precedes the other in lexicographical order.
8. Create a program which calculates the length of a string.
9. Create a program which swaps the smallest and greatest elements of an array.
10. Create a program which gets a string and pints the number of lines.
11. Write a program which counts the number of vowels and consonants in a
    string.
12. Read the word "árvíztűrőtükörfúrógép" in a string and print its size in
    bytes.
13. Create a program which gets an array as input and determines whether it
    contains two amicable numbers. Two numbers are amicable if the sum of their divisors, that are less than themselves, equals the other. For example 220
    and 284 are amicable.
14. Create a program which transforms the column name->number conversion of an
    excel sheet (A -> 1, Z -> 26, AA -> 27, ...)
15. Create a program which gets a 101 element integer array input and determines
    its middle element. The middle element is the one which has as many greater
    elements than smaller.
16. Create a program which determines all permutation of a word's characters.
17. Create a program which determines the greatest triangle's are where the
    triangles' side lengths are given in an array. For example: the array
    [1, 3, 4, 5, 7] can generate the following triangles: (1, 3, 4), (1, 3, 5),
    (1, 3, 7), (1, 4, 5), (1, 4, 7), ...
18. Create a program which gets a string and counts the number of words. (Should
    work like `wc` command).

# Pointers, arrays

1. Change the value of a variable via a pointer.
2. Change the value of a pointer through a pointer to a pointer. Then change the
   value pointed by the pointed pointer as well!
3. Can you create a pointer to itself? What would be its type? Why not? Compare
   the sizes of pointers to different types of variables. Explain why the result
   is logical!
4. Write a function that returns the sum of the elements in an array received as
   a parameter. The array is passed using a pointer to the first element and an
   integer variable containing a length. Let's write the function without using
   the `operator[]`, using pointer arithmetic. Is it possible to find the size
   of the array inside the function without the variable containing the length?
5. Redesign the previous function so that we get the array using a pointer to
   the first element and a pointer to the last element. What happens if we
   overindex by one? What happens if we overindex by more?
6. Redesign the previous program to calculate an average. How can we calculate
   the size of the array from the pair of pointers?
7. What happens when a function returns a pointer to a local variable that is
   dereferenced?
8. Let's dereference a null pointer. What is the result?
9. Explain why the `operator&` is needed in the case of `scanf()` when reading
   into an integer variable.
10. Write a function that, from two pointers pointing inside the same array,
    decides which one points to an element with a smaller index.
11. Write a function that returns a pointer to the maximum element of an array
    received as a parameter. What is the advantage and disadvantage of this
    compared to returning an index?
12. Can we apply the function written in the previous task to half of an array?
    How?
13. Can we apply the function written in the previous task to a single variable,
    as if it were an array with one element?
14. A function can also return a value using a return value or a pointer (e.g.
    `scanf()`). When should you use which one? What are the
    advantages/disadvantages of the methods?

# Read IO

1. Write a program that calculates the sum of positive numbers from 1 to *n*.
   Read *n* from standard input.
2. Write a program that swaps the first and last digits of a number with at
   least 3 digits!
3. Write a program that prints the first *n* powers of a number! Read the number
   from the standard input.
4. Guessing game: read a number until it matches the one you chose (first it can
   be a hard-coded constant or `#define`, then use the `rand()` function). In
   case of a wrong guess, help if the guess was too small or too big. (Try to
   give a solution with several types of cycles, or try how the if statements
   can be replaced with a ternary operator.)
5. Complete the guessing program by counting the wrong attempts, then give a
   text evaluation based on this value!
6. Find and write all the Armstrong numbers between 0 and *x* on the screen.
   read *x* from standard input. A number with *n* digits is called an Armstrong
   number if all its digits are raised to the *n*-th power and added to give the
   original number. For example, for 153, 153=1^3+3^3+5^3

# IO, Strings

1. Write a program that reads a string from the standard input and counts the
   number of characters and words in it! Use the `fgets()` function to read.
2. Write a program that reads a second string and compares it with the previous
   one! Do the task with a built-in operation from the `string.h` library, and
   without it.
3. Copy the previous string into a third string! Complete the task with or
   without a built-in action.
4. Create a string as an array of characters and one as a pointer! Try to
   replace one character in both versions! What is the difference between the
   two?
5. Create a text file with any text. Write a program in which you open the file
   using the `fopen()` function and read the contents of the file by calling the
   `fgets()` function. Convert the scanned text to all uppercase letters and
   write the uppercase text to the standard output! After reading, close the
   file with the `fclose()` function.
6. Complete the previous task by writing the uppercase text not to the standard
   input, but to another file, using the `fprintf()` function. Use the `fopen()`
   function to create a new file as well.
7. Create two new files containing the same number of arbitrary numbers. Read
   the numbers from both files in parallel and write their product in a third
   file! To scan, use the `fscanf()` function.
8. Check which of the learned reading functions are suitable for reading
   characters one by one from the standard input!
9. Write a program that determines whether a string is a palindrome.
10. Write a program that determines how many consonants and vowels there are in
    the entered text! (We only use the letters of the English alphabet.)
11. Try to find out how many bytes are stored if you read the word
    "árvíztűrőtükörfúrógép" into a character array!

# IO, Strings 2
1. Write a program that asks the user for a text of up to 20 characters and
   makes a copy of it. Make sure that the copy only uses as much memory space as
   is absolutely necessary.
2. Create a function called `reverse()` that has a string parameter. The
   function should reverse the characters of the string locally. That is, the
   function returns the result in the same memory area that it received as a
   parameter. For example, the characters of a palindrome string are not changed
   in the function.
3. Modify the previous `reverse()` function so that it does not replace the
   characters locally, but creates another string and returns with it. Reserve
   the necessary memory dynamically!
4. Write a program that reads 5 words from the user and prints them in reverse
   order. Use an array.
5. Write a program that accepts a number as a command-line argument and reads as
   many words from the user as they enter. When you have entered them all, write
   the words in reverse order. Use an array.
6. Modify the solution of the previous task so that if the user types the word
   "END", the scan ends before reaching the limit specified as a command line
   argument. Use an array. Then write the contents of the array in reverse
   order.
7. Modify the solution of the previous task so that the program no longer asks
   the user for a command line argument, but reads words from the user until the
   input is not `EOF`, and then writes them out in reverse order. Use an array.
   Take care not to create memory garbage.
8. Create a function that expects an array of integers as a parameter. The
   function should return another array, in which the elements of the parameter
   array are reordered: the even ones at the front, the odd ones at the back.
   Manage memory dynamically!
9. Given a file, each line of which contains numbers with spaces separated.
   Write a program that reads line by line from this file and writes each row in
   ascending numerical order to a file called output.txt. Manage memory
   dynamically!

# Preprocessor

1. Write a macro that decides which of two numbers is bigger!
2. Write a macro that lists its parameters! (The parameter is not necessarily a
   string!)
3. Write a program that calculates the square of a number. Define the
   calculation of the square in another C file and declare it in a header file!
   Write `include` guard in the header file!
4. Rewrite the previous program by using a global variable instead of passing
   parameters!
5. Write a program to calculate the scalar product of two vectors!
6. Write a program to calculate the product of two matrices!
7. Write a macro to iterate over an interval `[n,m)`. For example,
   `FOR(i, 0, 10)` can be written instead of `for (i = 0; i < 10; ++i)`.
8. Write a function to calculate the transpose of a matrix!