
with Ada.Text_IO, PQueue;
use Ada.Text_IO;

procedure Demo is 
    package IQueue is new PQueue(Integer);
    use IQueue;

    q : Queue;
    x : Integer;
begin

    Put("Inserting : ");
    for i in 1..10 loop 
        Put(i'image & " ");
        Push(q, i);
    end loop;

    New_Line;
    New_Line;
    Put("Pop : ");
    for i in 1..10 loop 
        Put(Front(q)'image & " ");
        x := Pop(q);
    end loop;



end Demo;