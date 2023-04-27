


function FCount(g: in Grid) return Natural is
    c : Natural := 0;
begin
    for i in g'range(1) loop
        for j in g'range(2) loop
            c := c + g(i, j);
        end loop;
    end loop;
    return c;
end FCount;