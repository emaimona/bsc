with Ada.Text_IO, Ada.Strings, Ada.Command_Line, PForAll, PBag; 
use Ada.Text_IO, Ada.Command_Line; 


procedure Demo is
    type Elem is new String(1..12);
    type Index is new Positive;
    type Tarray is array(Index range<>) of Elem;

    procedure Decode(s: in out Elem) is
     temp : Character;
    begin
        for i in s'range loop
            for j in Integer'succ(i)..s'last loop
                if Character'Pos(s(i)) > Character'Pos(s(j)) then
                    temp := s(i);
                    s(i) := s(j);
                    s(j) := temp;
                end if;
            end loop;
        end loop;
    end Decode;

    procedure Print(s: in out Elem) is 
    begin
        for i in s'range loop
            Put(s(i));
        end loop;
        New_Line;
    end Print;

    procedure ForEach is new PForAll(Elem, Index, Tarray, Decode);
    procedure PrintAll is new PForAll(Elem, Index, Tarray, Print);
    --  A : Tarray := ("EMA", "Nue", "Mai");
    str : Elem := "Hello World!";




    --- BAG
        Type Elements is new Character;
        type EArray is array(Positive range<>) of Character;
        package Bags is new PBag(Character,EArray );

        --  procedure Print()
        --  procedure ForEach is new Bags.For_All(Print)

    b : Bags.Bag;
    arr : EArray := ("which mark will I get for the test?");


    ---
    type CharacterBagArray is array(Positive range 1..Ada.Command_Line.Argument_Count) of Natural;
    procedure Remove(e: Character; c: in out Natural) is
    begin
        if c = 2 then
        c := 0;
        end if ;
    end Remove;
    procedure Remove_With_Multiplicity_2_For_All is new Bags.For_All(Remove);

    bb : Bags.Bag;
begin

    Put_line(Argument(1));
    Put_line(bb'range);
    --  Decode(str);
    --  Put("Test string: ""Hello World!"" -> ");
    --  Print(str);

    --  New_Line;
    --  New_Line;
    -- Grade 3
    --  Bags.Insert_Array(b, arr);
    --  Put_line("The multiplicity of 'e' is: " & Natural'Image(Bags.Multiplicity(b, 'e')));


    New_Line;
    New_Line;
    -- Grade 4
    --  Bags.Insert_Array(b, "Haha, cought you!");
    --  Bags.Write_Multiplicities(b);
    --  New_line;
    --  Bags.Remove_With_Multiplicity(b, 2);
    --  Bags.Write_Multiplicities(b);
    

    --  Bags.Insert_Array(bb, "sasa oooglooff vitek boss bbos oslo");
    --  Bags.Write_Multiplicities(bb);
    --  New_line;
    --  Remove_With_Multiplicity_2_For_All(bb);
    --  Bags.Write_Multiplicities(bb);
end Demo;