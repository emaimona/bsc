

function Fibonacci(N: Positive) return Positive is
    A, B : Positive := 1;
    TMP : Positive;
begin
        for I in 3..N loop
            TMP := A + B;
            A := B;
            B := TMP;
        end loop;
    return B;
end Fibonacci;