

package Stacks is
	type Stacks is private;

	procedure Push(S : Stacks; value : Integer);
	procedure Pop(S : Stacks; value : out Integer);
private
	Subtype Stack_Index is Natural range 1..10;
	type Content_Type is array(Stack_Index) of Integer;


type Stacks is record
	Top: Stack_Index;
	Content: Content_Type;
end record;


end Stacks;