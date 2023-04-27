


function FCount_Value(g: in Grid) return Natural is 
    c : Natural := 0;
begin
    for i in g'range(1) loop
        for j in g'range(2) loop
            if cond(g(i, j)) then
                c := c + 1;
            end if;
        end loop;
    end loop;
    return c;
end FCount_Value;