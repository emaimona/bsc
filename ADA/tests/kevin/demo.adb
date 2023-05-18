with Ada.Text_IO, Ada.Numerics.Float_Random, Ada.Numerics.Discrete_Random; 
use Ada.Text_IO, Ada.Numerics.Float_Random;

procedure Demo is
    protected Printer is 
        procedure Print (s : in String);
    end Printer;

    protected Safe_Random is 
        procedure Init;
        function Generate return Float;
    private
        G: Generator;
    end Safe_Random;

    protected body Safe_Random is 
        procedure Init is
        begin
            Reset(G);
        end Init;

        function Generate return Float is
        begin 
            return Random(G) * (4.0 - 0.0) + 0.0;
        end Generate;
    end Safe_Random;

    protected body Printer is
        procedure Print (s : in String ) is 
        begin
            Put_Line (s);
        end Print;
    end Printer;


    task type Door(id: Positive) is 
        entry Open;
        entry Close;
        entry Set_Trap;
    end Door;

    type PDoor is access Door;
    type DoorAarray is array(1..5) of PDoor;

    protected House is 
        procedure Init;
        procedure GetDoor(D: out PDoor);
        procedure GetDoor(Id: Positive; D: out PDoor);
    private
        Doors : DoorAarray;
    end House;

    protected body House is 
        procedure Init is 
        begin
            for i in 1..5 loop 
                Doors(i) := new Door(I);
            end loop;
        end Init;

        procedure GetDoor(D: out PDoor) is 
            package Rand_Door is new Ada.Numerics.Discrete_Random(Positive); use Rand_Door;

            Rand_Id : Positive;
            G: Rand_Door.Generator;
        begin
            Reset(G);
            Rand_Id := (Rand_Door.Random(G) mod 5) + 1;
            D := Doors(Rand_Id);
        end GetDoor;


        procedure GetDoor(Id: Positive; D: out PDoor) is
        begin
            D := Doors(Id);
        end GetDoor;
    end House;


     task Kevin is 
        entry Catch;
    end Kevin;

    task body Kevin is 
        Door : PDoor;
    begin 
        for I in 1..5 loop 
            House.GetDoor(I, Door);
            Door.Set_Trap;
        end loop;

        select 
            accept Catch;
        or 
            delay 3.0;
        end select;
        Printer.Print("Kevin was caught!");
    end Kevin;


    task Burglar is
        entry Hit;
    end Burglar;

    task body Burglar is 
        Door: PDoor;
    begin
        delay 3.5;
        House.GetDoor(Door);
        Door.Open;
        --  select 
            accept HIt;
            delay 3.0;
            Printer.Print("Catching kevin!");
            --  select
                Kevin.Catch;
                Printer.Print("Kevin was caught!");
            --  or 
            --      delay 0.01;
            --      Printer.Print("Kevin escaped!");
            --  end select;
        --  end select;
        Door.Close;
    end Burglar;


    task type Trap;
    type PTrap is access Trap;

    task body Trap is
        randomNumber : Float;
    begin
        randomNumber := Safe_Random.Generate;
        Printer.Print ("Trap waiting for " & Float'Image(randomNumber) & " seconds");
        delay Duration(randomNumber);
        select 
            Burglar.Hit;
            Printer.Print ("Trap was triggered!");
        or 
            delay 0.01;
        end select;
    end Trap;

   

    task body Door is 
        isOPen : Boolean := False;
        T: PTrap;
    begin
        loop 
            select
                when (not isOPen) => accept Open do 
                    isOpen := True;
                    T := new Trap;
                    Printer.Print ("Door" & id'image & " was opened!");
                end Open;
            or
                when isOpen => accept Close do 
                    isOpen := False;
                    Printer.Print ("Door was closed!");
                end Close;
            or 
                accept Set_Trap do
                    T:= new Trap;
                end Set_Trap;
            or
                terminate;
            end select;
        end loop;
    end Door;


begin
    Safe_Random.Init;
    House.Init;
end Demo;