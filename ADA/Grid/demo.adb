with Ada.Text_IO, FCount, FMoreThan, FCount_Value, FMigrate;
use Ada.Text_IO;

procedure demo is     
    type Matrix is array(Positive range<>, Positive range<>) of Natural;
    function countNests is new Fcount(Positive, Matrix);
    function MoreThan is new FMoreThan(Positive, Matrix);

    function Cond(c : Natural) return Boolean is
    begin
        return c > 3;
    end Cond;

    function CountValue is new FCount_Value(Positive, Matrix, Cond);

    procedure Migrate is new FMigrate(Positive, Matrix);

    procedure Print(g: Matrix) is
    begin
        for i in g'range(1) loop
            New_Line;
            for j in g'range(2) loop
                Put(g(i, j)'Image & " ");
            end loop;
        end loop;
    end Print;
    nest : Matrix(1..5, 1..5) := ((others => 4),(others => 3),(others => 2),(others => 2),(others => 3));

    function Is_Even(N : Integer) return Boolean is
begin
   return N mod 2 = 0;
end Is_Even;

type My_Array is array (1 .. 5) of Integer;
A : My_Array := (1, 2, 3, 4, 5);
S : String(1..100) := ('d', 'c', others => ascii.nul);

 -- Returns true
begin
    A := (1, 3, others => 3);
    s(1..5) := "skdfa";
    put_line(S);
    Put_line("They are " & countNests(nest)'Image & " birds");
    Put_line("The Nest has more than 50 birds? " & MoreThan(nest, 50)'Image);
    Put_line("The Nest has" & CountValue(nest)'Image & " Nest with more than 3 birds");


    nest(3, 3) := 7;
    Print(nest);

    Migrate(nest,5);
    New_Line;
    Print(nest);


end demo;