with Ada.Text_IO; use Ada.Text_IO;

procedure Sum is
    type Index is new Integer;
    type Elem is new Integer;
    type TArray is array(Index range <>) of Elem;

    function Add_all(T: TArray) return Elem is
        S: Elem := 0;
    begin
        for i in 1..5 loop
            S := S + T(i);
        end loop;
        return S;
    end Add_all;
begin
    Put("")

end Sum;