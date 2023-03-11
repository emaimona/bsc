with Ada.Text_IO;
use Ada.Text_IO;

with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

with Factorial;

procedure nchoosek is 
    n, k, res : Integer;

begin
    Put_Line("Give n and k: ");
    Get(n);
    Get(k);
    Factorial(n , n);
    res := n;
    --  res := Factorial(n, n)  / (Factorial(k, k) * Factorial(n-k, n));
    Put_Line("The result is " & Integer'Image(res));

end nchoosek;