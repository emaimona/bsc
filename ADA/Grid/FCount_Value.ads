generic
    type Index is (<>);
    type Grid is array(Index range<>, Index range<>) of Natural;
    with function Cond(n: Natural) return Boolean;
function FCount_Value(g: in Grid) return Natural;