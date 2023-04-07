with Ada.Text_IO, Ada.Integer_Text_IO, Bags;
use Ada.Text_IO, Ada.Integer_Text_IO, Bags;

procedure main is
    bg : Bag(5);
begin

    insert_one(bg, 1);
    Put_Line("Is the Bag empty? " & Boolean'Image(is_empty(bg)));

end main;

