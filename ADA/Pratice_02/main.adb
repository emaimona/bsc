with Ada.Text_IO, Fibonacci, Gcd, Fact_rec, Swap, Eulr, Math; use Ada.Text_IO;

procedure Main is
    A : Integer := 4;
    B : Integer := 8;
    GCD, LCM: Integer;
begin
    Put_Line("The Fibonacci number is: " & Positive'Image(Fibonacci(6)));
    --  Put_Line("The GCD number is: " & Posetive'Image(Gcd(6, 3)));
    Swap(A, B);
    Put_Line("The Factorial is: " & Positive'Image(Math.factorial(6)));
    Put_Line("The A and B are: " & Positive'Image(A) & " " & Positive'Image(B));


    Eulr(A, B, GCD, LCM);
    Put_Line("The gcd " & Integer'Image(Math.gcd(A, B)) & "  and LCM " & Integer'Image(LCM));
    
end Main;