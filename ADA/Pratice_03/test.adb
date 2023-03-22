with Ada.Text_IO, Matrix_pack;
use Ada.Text_IO, Matrix_pack;


procedure test is
   M: Matrix := ((1,2),(1,2),(3,2));
   N: Matrix := ((3,5),(3,5),(6,4));
   Sum: Matrix(M'Range(1), M'Range(2));
   A: Matrix := ((1,2),(1,2),(3,2));
   B: Matrix :=((3,3,6),(5,5,4));
   Prod1: Matrix(A'Range(1),B'Range(2));
   E: Elem := 8;
   Prod2: Matrix(A'Range(1),A'Range(2));
   procedure Print (M: Matrix) is
   begin
      for I in M'Range(1) loop
         for J in M'Range(2) loop
            Put(Elem'Image(M(I,J))&" ");
         end loop;
         New_Line;
      end loop;
   end Print;
begin
   Sum:=M+N;
   Print(Sum);
   New_Line;
   --  
   Add(M,N);
   Print(M);
   New_Line;
   --  
   --  Prod1:=A*B;
   --  Print(Prod1);
   --  New_Line;
   --  
   --  Prod2:=E*A;
   --  Print(Prod2);
   --  New_Line;
   --  
   --  Multiply(E,A);
   --  Print(A);
end test;