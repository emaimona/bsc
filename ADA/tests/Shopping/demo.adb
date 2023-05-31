with ada.text_io, ada.numerics.float_random, ada.numerics.discrete_random;
use ada.text_io;

procedure demo is
    package PRandom is new ada.numerics.Discrete_Random(Natural);
    use PRandom;

    protected Printer is
        procedure Print (Line : in String);
    end Printer;

    protected body Printer is 
        procedure Print (Line : in String) is
        begin
            put_line(Line);
        end Print;
    end Printer;

    protected Manager is
        procedure serverClient;
        function isClosed return Boolean;
    private
        served : Natural := 0;
        notServed : Natural := 15;
        closed : Boolean := False;
    end Manager;


    

    task type sport is
        entry enter;
        entry go_out;
        entry close;
    end sport;
    type PSport is access sport; 

    task body sport is
        G: PRandom.Generator;
        count : Natural := 0;
        sold : Natural := 0;
    begin
        PRandom.Reset(G);
    
        delay 0.2;
        while not Manager.isClosed loop
            select 
                accept enter;
                    count := count + 1;
                    sold := sold + 1;
                    Manager.serverClient;
            or 
                accept go_out;
                count := count - 1;
            or 
                accept close;
                exit;
            or
                delay 0.1;
                if count = 0 then 
                    exit;
                end if;
            end select;
        end loop;



        delay 0.3;
        Printer.Print("Sport is closed! And sold " & Natural'Image(sold) & " products!");
    end sport;   


    task type shoes is
        entry enter;
        entry go_out;
        entry close;
    end shoes;
    type PShoes is access shoes;

    task body shoes is
        G: PRandom.Generator;
        count : Natural := 0;
        sold : Natural := 0;
    begin
        PRandom.Reset(G);
        delay 0.2;
        while not Manager.isClosed loop
            select 
                accept enter;
                count := count + 1;
                sold := sold + 1;
                Manager.serverClient;
            or 
                accept go_out;
                count := count - 1;
            or 
                accept close;
                exit;
            or 
                delay 0.1;
                if count = 0 then 
                    exit;
                end if;
            end select;
        end loop;


        delay 0.3;
         Printer.Print("Shoes is closed! And sold " & Natural'Image(sold) & " products!");
    end shoes;
    
    
    task type electronics is
        entry enter;
        entry go_out;
        entry close;
    end electronics;
    type PElectronics is access electronics;

   task body electronics is
        G: PRandom.Generator;
        count : Natural := 0;
        sold : Natural := 0;
    begin
        PRandom.Reset(G);
        delay 0.2;
        while not Manager.isClosed loop
            select 
                accept enter;
                count := count + 1;
                sold := sold + 1;
                Manager.serverClient;
            or 
                accept go_out;
                count := count - 1;
            or 
                accept close;
                exit;
            or 
                delay 0.1;
                if count = 0 then 
                    exit;
                end if;
            end select;
        end loop;
        
        delay 0.3;
        Printer.Print("Electronics is closed! and sold " & Natural'Image(sold) & " products!");
    end electronics; 

    ElShop : array(1..2) of PElectronics;
    SpShop : array(1..2) of PSport;
    ShShop : array(1..2) of PShoes;

    protected body Manager is
        function isClosed return Boolean is 
        begin
            Printer.Print("Manager is checking if all shops are closed!");
            return closed;
        end isClosed;

        procedure serverClient is
        begin
            if served < 2 then
                served := served + 1;
                notServed := notServed - 1;
                Printer.Print("Client served !");
                if served = 2 then 
                    closed := True;
                end if;
            else
                if not closed then 
                    Printer.Print("Manager is closing all shops!");
                    for i in 1..2 loop
                        select ElShop(i).close; else null; end select;
                        select SpShop(i).close; else null; end select;
                        select ShShop(i).close; else null; end select;
                    end loop;
                end if;
                Printer.Print("Manager has closed all shops!");
            end if;
        end serverClient;
    end Manager;


    task type Customer(name : access String);
    type PCustomer is access Customer;

    task body Customer is
        rand : Natural;
        G: Generator; 
    begin
        Reset(G);
        delay 0.1;
        
        rand := Random(G) rem 2 + 1;
        Printer.print(name.all & " is going to Sport!");
        select
            SpShop(rand).enter;
            SpShop(rand).go_out;
            Printer.Print(name.all & " entered and exited Sport");
        else
            Printer.Print(name.all & " found Sport closed!");
            delay 0.1;
        end select;
        --  New_Line;

        Printer.Print(name.all & " is going to shoes!");
       
        rand := Random(G) rem 2 + 1;
        select 
            ShShop(rand).enter;
            ShShop(rand).go_out;
            Printer.Print(name.all & " entered and exited Shoes");
        else 
            Printer.Print(name.all & " found Shoes closed!");
            delay 0.1;
        end select;

        --  New_Line;
        rand := Random(G) rem 2 + 1;
        Printer.Print(name.all & " is going to electronics!");
        select
            ElShop(rand).enter;
            ElShop(rand).go_out;
            Printer.Print(name.all & " entered and exited Electronics");
        else 
            Printer.Print(name.all & " found Electronics closed!");
        end select;
    end Customer;
    

    person : Pcustomer;
begin

    for i in 1..2 loop
        ElShop(i) := new Electronics;
        SpShop(i) := new Sport;
        ShShop(i) := new Shoes;
    end loop;
   
   for i in 1..3 loop
        person := new Customer(new String'(Character'image(Character'Val(64 + i))));
    end loop;
end demo;