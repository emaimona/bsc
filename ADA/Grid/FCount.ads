

generic
    type Index is (<>);
    type Grid is array(Index range<>, Index range<>) of Natural;


function FCount(g: in Grid) return Natural;