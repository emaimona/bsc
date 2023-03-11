
procedure Eulr(A, B : in Positive; GCD, LCM: out Positive) is
    X : Positive := A;
    Y : Integer := B;
begin
    while X /= Y loop
        if X > Y then
            x := X - Y;
        else
            Y:= Y - X;
        end if;
    end loop;

    GCD := X;
    LCM := A*B/GCD;
end Eulr;