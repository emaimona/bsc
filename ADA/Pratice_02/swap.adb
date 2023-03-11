
procedure Swap(A, B : in out Integer) is
    TMP: Integer := A;
begin
    A := B;
    B := TMP;
end Swap;