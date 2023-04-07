generic
    type Elem is private;
    type Index is (<>);
    type TArray is array ( Index range <> ) of Elem;
    with function func(a: Elem; b: Elem) return Boolean is <>;
procedure Search(t: TArray; b: out Boolean; idx1: out Index; idx2: out Index);