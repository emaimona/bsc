
generic
    type Elem is (<>);
    type Tarray is array(Positive range<>) of Elem;
package PBag is

    type Bag is limited private;
    procedure Insert(b : in out Bag; e : Elem; c : Natural);
    function Multiplicity(b : in out Bag; e : Elem) return Natural;
    procedure Insert_Array(b : in out Bag; arr : Tarray);
    procedure Remove_With_Multiplicity(b: in out Bag; c : Natural);
    procedure Write_Multiplicities(b: in out Bag);

    generic 
        with procedure Op(e: Elem; c: in out Natural);
    procedure For_All(b : in out Bag);
private
    type CArray is array(Elem range<>) of Natural;
type Bag is record 
    container : CArray(Elem'first..Elem'last) := (Others => 0);
end record;

end PBag;