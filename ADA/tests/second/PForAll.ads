

generic
    type Elem is private;
    type Index is (<>);
    type Vector is array(Index range <>) of Elem;
    with procedure Decode( S: in out Elem );
procedure PForAll( V: in out Vector );