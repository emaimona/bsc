

package Matrix_pack is
    type Index is new Integer;
    type Elem is new Integer;
    type Matrix is array(Index range <>, Index range <>) of Elem;

    procedure Add(A, B: in out Matrix);
    procedure Multiply(A, B: in out Matrix; C: out Matrix);

    function "+"(A, B: Matrix) return Matrix;

end Matrix_pack;