with Ada.Text_IO; use Ada.Text_IO;

procedure factorial(x : Integer; num: out Integer) is 
begin
    num := 1;

    for i in 2..6 loop
        num := num * i;
    end loop;
end factorial;