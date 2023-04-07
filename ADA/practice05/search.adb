procedure Search(t: TArray; b: out Boolean; idx1: out Index; idx2: out Index) is
begin
    b:=False;
    for i in reverse t'Range loop
        for j in Index'Succ(i)..t'last loop
            if func(t(i), t(j)) then 
                idx1 := i;
                idx2 := j;
                b := True;
                exit;
            end if;
        end loop;
    end loop;
end Search;