
generic
      type Elem is (<>);

package PQueue is 
      type Queue is private;

      function Front(q: Queue) return Elem;
      function Size(q: Queue) return Natural;
      procedure Push(q: in out Queue; e: Elem);
      function Pop(q: in out Queue) return Elem;
      function Is_Empty(q: Queue) return Boolean;
private
      type Node;
      type Pointer is access Node;
      type Node is record
            Data: Elem;
            Next: Pointer := null;
      end record;
type Queue is record 
      Front : Pointer := null;
      Size : Natural := 0;
end record;

end PQueue;