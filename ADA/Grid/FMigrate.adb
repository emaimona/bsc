

procedure FMigrate(g: in out Grid; max: in Natural) is
    count : Natural;
    idi, idj : Index;

    function isOkay(i, j : Index) return Boolean is
    begin
        return i >= g'First(1) and i <= g'Last(1) and j >= g'First(2) and j <= g'Last(2);
    end isOkay;

    procedure helper(g: in out Grid; i, j : Index; count: in out Natural) is
    begin 
         while isOkay(i, j) and then g(i, j) < max and then count /=0 loop
            g(i, j) := g(i, j) + 1;
            count := count - 1;
        end loop;
    end helper;
begin
    for i in g'range(1) loop
        for j in g'range(2) loop 
            if g(i, j) > max then
                count := g(i, j) - max;
                g(i, j) := g(i, j) - count;

                if i /= Index'last then
                    idi := Index'succ(i);
                    idj := j;
                    helper(g, idi, idj, count);
                end if;

                if i /= Index'first then
                    idi := Index'pred(i);
                    idj := j;
                    helper(g, idi, idj, count);
                end if;

                if j /= Index'last then
                    idi := i;
                    idj := Index'succ(j);
                    helper(g, idi, idj, count);
                end if;
            
                if j /= Index'first then
                    idi := i;
                    idj := Index'pred(j);
                    helper(g, idi, idj, count);     
                end if;   
            end if;
        end loop;
    end loop;

end FMigrate;