with Ada.Text_IO, Lab3; use Ada.Text_IO, Lab3;

procedure Main is
    arr: Integer_array := (1,2,3,4,5);
    newArr : Integer_array  := (3, 5, 6, 7, 2, 0, 1);

    mat : Matrix := ((11, 22, 33, 44, 55), (1, 8, 3, 8, 8) , (10, 10, 20, 30, 1));
begin
    New_Line;
    Put_Line("The array sum is" & Integer'Image( arraySum(arr, 1)) );

    -- 17
    bubleSort(newArr, False);
    printArray(newArr);
    

    -- Start
    New_Line;
    Put_Line("Printing spiral..");
    printSpiral(mat);

end Main;