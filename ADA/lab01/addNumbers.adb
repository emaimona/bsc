with Ada.Text_IO;
use Ada.Text_IO;

with Sum;

procedure addNumbers is 
    num : Integer := 0;
begin
    for i in 1..10 loop 
        num := num + i;
        Put_Line(Integer'Image(num));
    end loop;

    Put_Line(Integer'Image(Sum(100)));
end addNumbers;