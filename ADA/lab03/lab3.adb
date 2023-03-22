with Ada.Text_IO; use Ada.Text_IO;


package body Lab3 is 
    function arraySum(arr: Integer_array; index: Positive) return Integer is 
    begin
        if index = arr'Last then
            return arr(index);
        end if;
        return arr(index) + arraySum(arr, index+1);
    end arraySum;


    procedure bubleSort(arr: in out Integer_array; asc: Boolean) is
        temp : Integer := 0;
    begin
        for i in arr'Range loop
            for j in 2 .. arr'Last loop
                if (asc and arr(j-1) > arr(j)) or (not asc and arr(j-1) < arr(j)) then
                    temp := arr(j-1);
                    arr(j-1) := arr(j);
                    arr(j) := temp;
                end if;
            end loop;
        end loop;
    end bubleSort;



    procedure printArray(arr: Integer_array) is

    begin
        for i in arr'Range loop
            Put(Integer'Image( arr(i) ) & " ");
        end loop;
        Put_Line("");
    end printArray;


    

    procedure printSpiral(mat: Matrix) is
        visited : BoolMatrix(mat'Range(1), mat'Range(2)) ;

        row : Positive;
        col : Positive;
    begin

        row := mat'Length(1);
        col := mat'Length(2);

        for i in mat'Range(1) loop
            for j in mat'Range(2) loop
                visited(i, j) := False;
            end loop;
        end loop;

        for i in mat'Range(1) loop
            for j in mat'Range(2) loop
                if (not visited(i, j)) then
                    dfs(i, j, row, col, mat, visited);
                end if;
            end loop;
        end loop;
    end printSpiral;


    procedure dfs(i, j, row, col : Positive; mat: Matrix; visited: in out BoolMatrix) is
        xdirections : Integer_array := (1, 0, -1, 0);
        ydirections : Integer_array := (0, 1, 0, -1);
        x, y : Positive;
    begin
        visited(i, j) := True;
        Put(Integer'Image(mat(i, j)) & " ");

        for span in xdirections'Range loop
            --  x := i + xdirections(span);
            --  y := j + ydirections(span);

            --  if (x >= 1 and x <=row and y>=1 and y<=col) then
            --      if ( not visited(x, y)) then
            --          dfs(x, y, row, col, mat, visited);
            --      end if;
            --  end if;
            Put( -s);
        end loop;
    end dfs;

end Lab3;