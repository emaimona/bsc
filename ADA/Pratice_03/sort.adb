with Ada.Text_IO; use Ada.Text_IO;

procedure sort is
    type Index is new Integer;
    type Elem is new Integer;
    type TArray is array(Index range <>) of Elem;


    function Max_Pos (T:TArray ) return Index is
        M: Index := T'First;
    begin
        for I in T'Range loop
            if T(M) < T(I) then
                M := I;
            end if;
        end loop;
        return M;
    end Max_Pos;

    procedure Swap(A, B: in out Elem) is 
        Temp: Elem := A;
    begin 
        A := B;
        B := Temp;
    end Swap;

    procedure Order( T: in out TArray) is
        M: Index;
    begin
        if T'Length > 1 then
            M := Max_Pos(T);
            Swap(T(M), T(T'Last));
            Order(T(T'First..Index'Pred(T'Last)));
        end if;
    end Order;

    T: TArray := (3, 5, 4, 7, 1);
begin
    Order(T);
    for I in T'Range loop
        Put(Elem'Image(T(I)) & " ");
    end loop;
end sort;