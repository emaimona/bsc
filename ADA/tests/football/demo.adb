with ada.text_io, ada.real_time, ada.numerics.Float_Random;
use ada.text_io, ada.real_time, ada.Numerics.Float_Random;

procedure demo is
    protected Printer is 
        procedure Print(s : in String);
    end Printer;

    protected body Printer is 
        procedure Print(s : in String) is
        begin
            put_line(s);
        end Print;
    end Printer;

    protected Safe_Random is
        procedure Init;
        function Generate return Float;
    private 
        G : Generator;
    end Safe_Random;

    protected body Safe_Random is
        procedure Init is
        begin
            Reset(G);
        end Init;

        function Generate return Float is 
        begin
            return Random(G);
        end Generate;
    end Safe_Random;


    task Gate is 
        entry Shoot(result: out Boolean);
        entry Keeper(isReady : Boolean);
    end Gate;

    task body Gate is 
        ready : Boolean := False;
    begin
        loop
            select
                when ready => 
                    accept Shoot(result : out Boolean) do
                        if (Safe_Random.Generate > 0.5) then 
                            result := True;
                        else 
                            result := False;
                        end if;
                    end Shoot;
                or
                    accept Keeper(isReady : Boolean) do
                        ready := isReady;
                        if ready then 
                            Printer.Print("GoalKeeper is ready!");
                        else 
                            Printer.Print("GoalKeeper is now tired!");
                        end if;
                    end Keeper;
                or 
                    terminate;
            end select;
        end loop;
    end Gate;


    task GoalKeeper;

    task body GoalKeeper is 
        start : Time := Clock;
        timer: Time := Milliseconds(1500);

    begin
        Gate.Keeper(true);
        loop 
            delay until timer;
            if Safe_Random.Generate > 0.7 then 
                Gate.Keeper(True);
            else 
                Gate.Keeper(False);
            end if;
            exit when To_Duration(Clock - start) > 10.0;
        end loop;
        Gate.Keeper(false);
    end GoalKeeper;


    task Player;

    task body Player is
        scored : Boolean;
    begin
        delay 0.1;
        loop
            Printer.Print("Player attemps to shoot!");
            select 
                Gate.Shoot(scored);
                if scored then
                    Printer.Print("Player scored!");
                    exit;
                else 
                    Printer.Print("Player missed!");
                end if;
            else
                Printer.Print("Player waits the GoalKeeper to be ready!");
                delay 0.1;
            end select;
        end loop;
    end Player;

begin
    Safe_Random.Init;
end demo;