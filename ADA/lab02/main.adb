with Ada.Text_IO, lab2; use Ada.Text_IO, lab2;


procedure Main is 

begin 
    Put_Line("");
    Put_Line("");

    -- 9
    Put_Line("Add the digits of 123 " & Natural'Image(addDigits(123)));

    -- 10
    Put_Line("Is 9325 divisible by ? " & Boolean'Image(dividesby9(9325)));
    Put_Line("Is 9234  divisible by ? " & Boolean'Image(dividesby9(9234)));


    -- 11
    Put_Line("Printing perfect numbers from 0 to 10000");
    findPerfects;

    -- 13
    Put_Line("Is 1234 Palindrome? " & Boolean'Image(isPalindrome(1234)));
    Put_Line("Is 22322 Palindrome? " & Boolean'Image(isPalindrome(22322)));


    -- 14
    Put_Line("3^2 =" & Natural'Image(nthPower(3, 2)));
    Put_Line("1341^1 =" & Natural'Image(nthPower(1341, 1)));


    -- 15
    Put_Line(" 4! = " & Positive'Image(factorial(4)));
    Put_Line(" 5! = " & Positive'Image(factorial(5)));

    Put_Line("");
end Main;