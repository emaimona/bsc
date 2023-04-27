

generic
    type Index is (<>);
    type Grid is array (Index range <>, Index range <>) of Natural;
    --  with function "<" (a: Index; b: Index) return Boolean is <>;

package Pgrid is 
    type grid(n:Index; m:Index) is limited private;

    function count(g : grid) return Natural;
    procedure occupyNest(g : in out grid);

private
    type grid(n: Index; m:Index) is record 
        Nest : Matrix(Index'first..n, Index'first..m);
        col: Index := n;
        row : Index := m;
        I : Index := Index'first;
        J : Index := Index'first;
    end record;

end Pgrid;

