

generic
    type Index is (<>);
    type Elem is private;

package Pstack is

    type Stack(Max: Index) is limited private;

    procedure Push(el : Elem; st : in out Stack);
    procedure Pop(st: in out Stack);
    procedure Top(st: in Stack);
    function IsEmpty(st : in out Stack) return Boolean;

    generic
        with procedure operation(el : in out Elem);
        procedure ForEach(st : in out Stack);

private
    type sarray is array (Index range <>) of Elem;

    type Stack(Max : Index) is record
        top : Index := Index'First;
        Content : sarray (Index'First..Max);
    end record;
end Pstack;