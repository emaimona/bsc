-- body

package body Math is
    function gcd(a, b : Positive) return Positive is
         X: Positive  := A;
        Y: Natural := B;
        TMP: Natural;
    begin
        while Y /= 0 loop
        TMP  := X mod Y;
        X := Y;
        Y := TMP;
        end loop;
        return X;
    end gcd;

    --
    function factorial(n: Natural) return Positive is
        fact : Positive := 1;
    begin
        for i in 1..n loop
            fact := fact * i;
        end loop;

        return fact;
    end factorial;

end Math;