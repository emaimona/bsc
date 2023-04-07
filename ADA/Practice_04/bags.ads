

--  The bag can contain elements in the 1..100 interval.
--  Define the insert_one, insert_multiple, extract_one, extract_multiple, 
--  is_empty, print operations.
--  --  hint: The index type can be t
package Bags is
    subtype Elem is Natural;
    type TArray is array(positive range <>) of Elem;
    type Bag(Max: Positive) is limited private;
    
    procedure insert_one(B: in out Bag; num: Elem);
    procedure insert_multiple(B: in out Bag; arr: TArray);
    --  procedure print_operations(B: Bag);
    function extract_one(B: in out Bag; num: Elem) return Integer;
    function extract_multiple(B: in out Bag; arr: in out TArray) return TArray;
    function is_empty(B: in out Bag) return Boolean;
    
private

type Bag(Max: Positive) is record
    Content : TArray (1..Max);
    Counter : Elem := 0;
end record;
end Bags;