

generic
    type Index is (<>);
    type Grid is array(Index range<>, Index range<>) of Natural;

procedure FMigrate(g: in out Grid; max: in Natural);