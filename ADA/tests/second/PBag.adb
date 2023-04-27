with Ada.text_io;
use Ada.Text_Io;

package body PBag is
    procedure Insert(b : in out Bag; e : Elem; c : Natural) is 
    begin
        b.container(e) := b.container(e) + c;
    end Insert;


    function Multiplicity(b : in out Bag; e : Elem) return Natural is
    begin
        return b.container(e);
    end Multiplicity;

    procedure Insert_Array(b : in out Bag; arr : Tarray) is

    begin
        for i in arr'Range loop
            Insert(b, arr(i), 1);
        end loop;
    end Insert_Array;

   
    procedure Remove_With_Multiplicity(b: in out Bag; c : Natural) is
    begin
        for i in b.container'range loop
            if b.container(i) = c then
                b.container(i) := 0;
            end if;
        end loop;
    end Remove_With_Multiplicity;
    
    procedure Write_Multiplicities(b: in out Bag) is
        c : Natural := 0;
    begin
        Put_Line("Bag {");
        for i in b.container'range loop
            if b.container(i) /= 0 then
                Put_Line("  " & Elem'image(i) & " : " & Natural'image(b.container(i)));
                c := c + b.container(i);
            end if;
        end loop;
        Put_line("Count : " & Natural'image(c));
        Put_Line("}");
    end Write_Multiplicities;



    procedure For_All(b : in out Bag) is
    begin
        for i in b.container'range loop
            Op(i, b.container(i));
        end loop;
    end For_All;

end PBag;