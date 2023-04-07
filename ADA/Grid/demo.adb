with Ada.Text_IO, Pgrid;
use Ada.Text_IO;



procedure demo is     
    type Index is new Positive;
    type Matrix is array (Positive range <>, Positive range <>) of Natural;
    package Nest is new Pgrid(Positive, Matrix);


    hub : Nest.grid(10, 10);
begin

    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Nest.occupyNest(hub);
    Put("The count is: " & Natural'Image(Nest.count(hub)));
end demo;