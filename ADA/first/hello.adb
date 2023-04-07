with Ada.Text_IO; use Ada.Text_IO;
procedure Hello is
begin

   Put_Line("Hello WORLD! " & Integer'Image((-12) mod (-5)));
end Hello;