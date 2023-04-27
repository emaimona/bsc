

function FMoreThan(g: in Grid; max: in Natural) return Boolean is 
    c : Natural := 0;
begin

    for i in g'range(1) loop
        for j in g'range(2) loop
            if c > max then
                return True;
            end if;
            c := c + g(i, j);
        end loop;
    end loop;
    return False;
end FMoreThan;