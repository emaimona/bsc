with Ada.Text_IO;
use Ada.Text_IO;

function sum(x : Integer) return Integer is
    result : Integer := 0;
begin
    for i in 1..x loop
        result := result + i;
    end loop;

    return result;
end sum;