generic
    type Elem is private;

package Stackgen is 
    type Stack is limited private;
    procedure Push(V: in out Stack; E: Elem);
    procedure Pop(V: in out Stack; E: out Elem);

    function Front(V: Stack) return Elem;
    function Is_Empty(V: Stack) return Boolean;
    function Size(V: Stack) return Natural;

private 
    type Node;
    type Pointer is access Node;
    type Node is record
                    Data: Elem;
                    Next: Pointer := null;
                end record;
    type Stack is record
                    Size: Natural := 0;
                    Top: Pointer := null;
                end record;
end Stackgen;