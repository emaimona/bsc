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

    


    Put_Line("");
end Main;