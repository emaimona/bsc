
with Ada.Text_IO;
use Ada.Text_IO;

package body Pstack is
    procedure Push(el : Elem; st : in out Stack) is
    begin
        st.Content(st.top) := el;
        st.top := Index'succ(st.top);
    end;
    procedure Pop(st: in out Stack) is
    begin
        null;
    end Pop;


    procedure Top(st: in Stack) is
    begin 
        null;

    end Top;


    function IsEmpty(st : in out Stack) return Boolean is
    begin
        return st.top = Index'First;
    end isEmpty;


    procedure ForEach(st : in out Stack) is 
    begin
        for i in Index'first..Index'pred(st.top) loop 
            operation(st.Content(i));
        end loop;
    end ForEach;

end Pstack;