--  with Aswap, Ada.Text_IO;
--  use Aswap, Ada.Text_IO;
with Search, Ada.Text_IO;
use Ada.Text_IO;

procedure demo is
    type TInt is array (Integer range <>) of Integer;

    function is_equal (a: Integer; b: Integer) return Boolean is
    begin
        return (a = b);
    end is_equal;

    procedure my_search is new Search(Integer, Integer, TInt, is_equal);

    a: TInt(1..5) := (1, 2, 3, 4, 1);
    b: Boolean;
    idx1: Integer;
    idx2: Integer;

begin
    my_search(a, b, idx1, idx2);
    if b then 
        Put_line("The first duplicates were found at: " & Integer'Image(idx1) & " and"  & Integer'Image(idx2));
    else 
        Put_line("No duplicates found!");
    end if;

end demo;






