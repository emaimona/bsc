
function Fact_rec(N: Natural) return Positive is

begin
    if N > 1 then
        return N * Fact_rec(N -1);
    else
        return 1;
    end if;
end Fact_rec;