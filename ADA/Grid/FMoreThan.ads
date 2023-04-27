


generic
    type Index is (<>);
    type Grid is array(Index range<>, Index range<>) of Natural;

function FMoreThan(g: in Grid; max: in Natural) return Boolean;