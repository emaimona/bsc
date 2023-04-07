with Ada.Text_IO, Pstack;
use Ada.Text_IO;

procedure demo is
    type Index is new Integer range 1..100;
    type Elem is new Positive;
    package pilha is new Pstack(Index, Elem);
    use pilha;
    procedure print(el : in out Elem) is 
    begin
        Put(Elem'Image(el) & " ");
    end print;

    procedure multiply(el : in out Elem) is
    begin
        el := el * el;
    end multiply;

    procedure mul is new ForEach(multiply);
    procedure faz is new pilha.ForEach(print);

    max : Index := 10;
    st: pilha.Stack(max);

begin
    pilha.push(10, st);
    push(14, st);
    push(19, st);
    Put_Line("Is the stack empty? " & Boolean'Image(pilha.isEmpty(st)));
    mul(st);
    faz(st);
end demo;