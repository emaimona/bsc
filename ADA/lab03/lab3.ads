


package Lab3 is
    type Integer_array is array (Positive range <>) of Integer;
    type Matrix is array(Positive range<>, Positive range<>) of Integer;
    type BoolMatrix is array(Positive range <>, Positive range<>) of Boolean;


    function arraySum(arr: Integer_array; index: Positive) return Integer;
    
    procedure bubleSort(arr: in out Integer_array; asc: Boolean);
    procedure printArray(arr: Integer_array);
    procedure printSpiral(mat: Matrix);

    procedure dfs(i, j, row, col: Positive; mat: Matrix; visited: in out BoolMatrix);

end Lab3;