

procedure Sort( T: in out TA) is
    procedure My_Swap is new Swap(Elem);
    function Max_Position is new max_pos(Elem, Index, TA);
    Mh: Index;
begin
    for i in reverse T'Range loop
        Mh := Max_Position(T(T'First.. I));
        My_Swap(T(I), T(Mh));
    end loop;

end Sort;