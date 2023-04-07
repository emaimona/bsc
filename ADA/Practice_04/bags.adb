

--  The bag can contain elements in the 1..100 interval.
--  Define the insert_one, insert_multiple, extract_one, extract_multiple, 
--  is_empty, print operations.
--  --  hint: The index type can be t
package body Bags is
    procedure insert_one(B: in out Bag; num: Elem) is
    begin
        B.Content(num) := B.Content(num) + 1;
        B.Counter := B.Counter + 1;
    end insert_one;
    
    
    procedure insert_multiple(B: in out Bag; arr: TArray) is 
    begin
        for i in arr'Range loop
            insert_one(B, arr(i));
        end loop;
    end insert_multiple;



    function extract_one(B: in out Bag; num: Elem) return Integer is 
    begin
        if (B.Content(num) > 0) then
            B.Content(num) := B.Content(num) - 1;
            return num;
        end if;
        return -1;
    end extract_one;


    function extract_multiple(B: in out Bag; arr: in out TArray) return TArray is
    begin
        for i in arr'Range loop
            if extract_one(B, arr(i)) = -1 then
                arr(i) := -1;
            end if;
        end loop;
        return arr;
    end extract_multiple;

    function is_empty(B: in out Bag) return Boolean is
    begin 
        return B.Counter = 0;
    end is_empty;
end Bags;