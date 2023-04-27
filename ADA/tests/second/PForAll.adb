

procedure PForAll( V: in out Vector ) is

begin
    for i in V'Range loop
        Decode(V(i));
    end loop;
end PForAll;