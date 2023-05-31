with Ada.Text_IO, Ada.Numerics.Float_Random, Ada.Numerics.Discrete_Random; 
use Ada.Text_IO, Ada.Numerics.Float_Random;

procedure Demo is
    type PString is access String;
    type Priority is new Integer range 0..2;

    package RandPriority is new Ada.Numerics.Discrete_Random(Priority);

    subtype NumOfImigration is Integer range 1..3;
    package RandImigrationOffice is new Ada.Numerics.Discrete_Random(NumOfImigration);
    
    protected Committee is 
        procedure Increase;
        function getCount return Natural;
    private
        Count : Natural := 0;
    end Committee;

    protected body Committee is 
        procedure Increase is 
        begin
            Count := Count + 1;
        end Increase;

        function getCount return Natural is 
        begin
            return Count;
        end getCount;
    end Committee;
    
    protected Printer is 
        procedure Print(s : String);
    end Printer;

    protected body Printer is 
        procedure Print(s : String) is 
        begin
            Put_Line(s);
        end Print;
    end Printer;

    protected Safe_Float_Random is 
        procedure Init;
        procedure Generate(Rand_num: out Float);
    private 
        G: Generator;
    end Safe_Float_Random;

    protected body Safe_Float_Random is 
        procedure Init is 
        begin
            Reset(G);
        end Init;

        procedure Generate(Rand_num: out Float) is 
        begin
            Rand_num := Random(G);
        end Generate;
    end Safe_Float_Random;

    protected Safe_Priority_Rand is 
        procedure Init;
        procedure Generate(Rand_num: out Priority);
    private 
        G: RandPriority.Generator;
    end Safe_Priority_Rand;

    protected body Safe_Priority_Rand is 
        procedure Init is 
        begin
            RandPriority.Reset(G);
        end Init;

        procedure Generate(Rand_num: out Priority) is 
        begin
            Rand_num := RandPriority.Random(G);
        end Generate;
    end Safe_Priority_Rand;

    protected Safe_Office_Rand is 
        procedure Init;
        procedure Generate(Rand_num: out NumOfImigration);
    private 
        G: RandImigrationOffice.Generator;
    end Safe_Office_Rand;

    protected body Safe_Office_Rand is 
        procedure Init is
        begin 
            RandImigrationOffice.Reset(G);
        end Init;

        procedure Generate(Rand_num: out NumOfImigration) is    
        begin
            Rand_num := RandImigrationOffice.Random(G);
        end Generate;
    end Safe_Office_Rand;


    task type Immigration is
        entry getResidence;
    end Immigration;

    task body Immigration is
        Rand : Float;
    begin 
        Safe_Float_Random.Generate(Rand);
        delay Duration(Rand);

        loop
            select 
                accept getResidence do 
                    Printer.Print("Immigration freshman get his residence");
                    Committee.Increase;
                end getResidence;
                delay 1.0;
            or 
                terminate;
            end select;
        end loop;
    end Immigration;

    type PImigratrion is access Immigration;
    Offices: array(1..3) of PImigratrion;

    task type Freshman(ID: PString);
    task body Freshman is 
        P: Priority;
        Rand_del: Float;
        GotResidence: Boolean := False;
        ImigrationID: NumOfImigration;
    begin
        Safe_Priority_Rand.Generate(P);
        Safe_Float_Random.Generate(Rand_del);
        Safe_Office_Rand.Generate(ImigrationID);

        while not GotResidence and P /= Priority'first loop 
            Printer.Print(ID.all & " has priority " & Priority'Image(P));
            select 
                Offices(ImigrationID).getResidence;
                Printer.Print(ID.all & " got his residence");
                GotResidence := True;
            or 
                delay Duration(Rand_del);
                if P = Priority'Last then 
                    Printer.Print(ID.all & " will try later in office" & ImigrationID'Image);
                    delay 0.7;
                end if;
                P := Priority'Pred(P);
            end select;
        end loop;

        if not GotResidence then
            Printer.Print(ID.all & " did not get his residence");
        end if;
    end Freshman;

    type PFreshman is access Freshman;
    FM: PFreshman;

begin
    Safe_Float_Random.Init;
    Safe_Priority_Rand.Init;

    for i in 1..3 loop 
        Offices(I) := new Immigration;
        delay 0.5;
    end loop;

    for i in 1..42 loop 
        FM := new Freshman(new String'(Integer'Image(i)));
        delay 0.5;
    end loop;

    Printer.Print("Number of accepted freshmen is: " & Committee.getCount'Image);
end Demo;