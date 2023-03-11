with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure CheckSign is
   x : Integer;
begin
   Put("Enter a number: ");
   Get(x);
   if x > 0 then
      Put_Line("The number is positive.");
   elsif x < 0 then
      Put_Line("The number is negative.");
   else
      Put_Line("The number is zero.");
   end if;
end CheckSign;