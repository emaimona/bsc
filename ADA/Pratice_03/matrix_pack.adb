

package body Matrix_pack is

    procedure Add(A, B: in out Matrix) is
    begin
        for I in A'Range(1) loop
            for J in A'Range(2) loop
                A(I, J) := A(I, J) + B(I-A'First(1) + B'First(1),   J-A'First(2)+ B'First(2));
            end loop;
        end loop;
    end Add;


    procedure Multiply(A, B: in out Matrix; C: out Matrix) is
    begin
        for I in A'Range(1) loop
            for J in A'Range(2) loop
                for K in A'Range(2) loop
                    C(I, J) := C(I, J) + A(I, K-B'First(1) + A'First(2)) * B(K-A'First(2) + B'First(1), J);
                end loop;
            end loop;
        end loop;
    end Multiply;


    function "+"(A, B: Matrix) return Matrix is 
        C: Matrix(A'Range(1), A'Range(2));
    begin
        for I in A'Range(1) loop
            for J in A'Range(2) loop
                C(I, J) := A(I, J) + B(I-A'First(1) + B'First(1),   J-A'First(2)+ B'First(2));
            end loop;
        end loop;

        return C;
    end "+";

end Matrix_pack;