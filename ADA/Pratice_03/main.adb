with Ada.Text_IO, Sum; use Ada.Text_IO;


procedure Main is
    arr : Sum.TArray := (1, 3, 4, 5);
    s : Sum.Elem;
begin

    s := Sum.Add_all(arr);
    Put("Hello world");
end Main;