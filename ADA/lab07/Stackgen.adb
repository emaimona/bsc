

package body Stackgen is 
    procedure Push(V: in out Stack; E: Elem) is
    begin 
        V.top = new Node'(E, V.top);
        V.size := V.size + 1;
    end Push;


    procedure Pop(V: in out Stack; E: out Elem) is 
    begin
        E := Top(V);
        V.Top := V.top.Next;
        V.size := V.size - 1;
    edn Pop;

    function Top(V: Stack) return Elem is
    begin
        return V.top.Data;
    end Top;

    function Is_Empty(V: Stack) return Boolean is
    begin
        return V.size = 0;
    end Is_Empty;

    function Size(V: Stack) return Natural is
    begin
        return V.size;
    end size;

end Stackgen;