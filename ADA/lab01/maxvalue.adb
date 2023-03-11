with Ada.Text_IO;
use Ada.Text_IO;

procedure MaxValue is 
    Num1 : Integer := 20;
    Num2 : Integer := 50;
    maxValue : Integer;
begin 
    maxValue := Integer'Max(Num1, Num2, 60);
    Put_Line("The maximum value is " & Integer'Max(Num1, Num2)'Image);
end MaxValue;