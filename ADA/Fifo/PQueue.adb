

package body PQueue is 
    function Front(q: Queue) return Elem is 
    begin 
        return q.Front.data;
    end Front;

    function Size(q: Queue) return Natural is 
    begin
        return q.Size;
    end Size;

    procedure Push(q: in out Queue; e: Elem) is 
        ptr: Pointer := q.Front;
    begin
        if ptr = null then
            q.Front := new Node'(e, null);
        else
            while ptr.Next /= null loop
                ptr := ptr.Next;
            end loop;
            ptr.Next := new Node'(e, null);
        end if;

    end Push;
    function Pop(q: in out Queue) return Elem is 
        val : Elem := Front(q);
    begin
        q.Front := q.Front.next;
        return val;
    end Pop;

    function Is_Empty(q: Queue) return Boolean is 
    begin
        return q.Size = 0;
    end Is_Empty;


end PQueue;