with ada.Text_IO, ada.Numerics.Discrete_Random, ada.Real_Time;
use ada.Text_IO, ada.Real_Time;


procedure Demo is 

    package RandomDur is new Ada.Numerics.Discrete_Random(Positive); use RandomDur;
    G: Generator;


    protected Printer is
        procedure Print (text : in String);
    end Printer;

    protected body Printer is
        procedure Print (text : in String) is
        begin
            Put_Line (text);
        end Print;
    end Printer;


    -- 
    protected Warehouse is
        procedure storeCargo;
        entry transferCargo;
    private
        counter: Natural := 0;
    end Warehouse;

    protected body Warehouse is
        procedure storeCargo is
        begin
            counter := counter + 1;
            Printer.Print("Cargo stored -> counter : " & Positive'image(counter));
        end storeCargo;

        entry transferCargo when counter > 0 is
        begin
            counter := counter - 1;
            Printer.Print("Cargo transfered -> counter : " & Positive'image(counter));
        end transferCargo;
    end Warehouse;

    



    -- 
    task type Shop is
        entry notification;
        entry sellCargo;
        entry keepOpen; 
    end Shop;

    task body Shop is 
        stock : Natural := 0;
        sold : Natural := 0;
    begin
        loop 
            select 
                accept notification do
                    Warehouse.transferCargo;
                    stock := stock + 1;
                    Printer.Print("Shop received cargo -> stock : " & Positive'image(stock));
                end notification;
            or
                accept sellCargo do
                    delay 0.2;
                    if stock = 0 then
                        Printer.Print("Stock is empty!");
                    else
                        stock := stock - 1;
                        sold := sold + 1;
                        Printer.Print("Shop sold cargo -> stock :" & Positive'image(stock));
                    end if;
                end sellCargo;
            or 
                accept keepOpen;
            or 
                delay 0.5;
                Printer.Print("Shop closed!   ->   Sold :" & Positive'image(sold) & ", Stock :" & Positive'image(stock));
                exit;
            end select;

        end loop;
    end Shop;

    type Shoop_Access is access Shop;
    type TShops is array(Natural range<>) of Shoop_Access;
    type TShops_access is access TShops;

    -- 
    task type deliveryTruck(Shops_Array : TShops_access);
    type deliveryTruck_Access is access deliveryTruck;

    task body deliveryTruck is
        randomNumber : Natural := 0;
    begin
        Reset(G);
        delay 3.0;
        loop
            delay 0.1;
            Warehouse.storeCargo;
            randomNumber := Random(G) rem 5;
            select
                Shops_Array(randomNumber).all.notification;
            or
                delay 0.01;
                Printer.Print("Delivery truck could not notify the Shop!");
                exit;
            end select;
        end loop;
        Printer.Print("Delivery truck finished!");
    end deliveryTruck;

    
    --
    task type Buyer(Shops_Array : TShops_access);
    type Buyer_Access is access Buyer;

    task body Buyer is
        randomNumber : Natural := 0;
    begin 
        -- ?they wait for notification from delivery truck or a buyer

        Reset(G);
        Printer.Print("Buyer generated!");

        delay 0.4;
        randomNumber := Random(G) rem 5;
        -- ?ENTER ??
        delay 0.1;
        Shops_Array(randomNumber).sellCargo;
    end Buyer;


    --
    task Scheduler;
    task body Scheduler is 
        startTime : Time := Clock;
        currentTime : Time;
        generatedBuyer : Buyer_Access; 
        truck : deliveryTruck_Access;
        Shops_Array : TShops_access := new TShops(0..4);
    begin 
        -- ? shops stop accepting new cargo or buyers

        for i in Shops_Array'range loop
            Shops_Array(i) := new Shop;
        end loop;

        truck := new deliveryTruck(Shops_Array);
        loop
            currentTime := Clock;
            for i in Shops_Array'range loop
                Shops_Array(i).keepOpen;
            end loop;
            delay 0.3;
            generatedBuyer := new Buyer(Shops_Array);
            exit when ada.Real_Time.To_Duration(currentTime - startTime) > 10.0;
        end loop;

        delay 3.0;
        Printer.Print("End of simulation!");
    end Scheduler;


    
begin
    null;
end Demo;