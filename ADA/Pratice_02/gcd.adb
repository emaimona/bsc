function gcd(A, B : in Positive) return Positive is
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