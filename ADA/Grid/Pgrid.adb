
package body Pgrid is 

    function count(g : grid) return Natural is 
        c : Natural := 0;
    begin
        for i in Index'first..g.I loop
            for i in Index'first..g.J loop
                c := c + 1;
            end loop;
        end loop;
        return c;
    end count;

    procedure occupyNest(g : in out grid) is
    begin
        if g.i < g.row and g.j < g.col then
            if g.i = g.row then 
                g.i := Index'succ(g.i);
            else 
                g.i := Index'succ(g.i);
                g.j := Index'first;
            end if;
        end if;
    end occupyNest;


end Pgrid;