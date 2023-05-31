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
            Printer.Print("Cargo stored -> Warehouse counter : " & Positive'image(counter));
        end storeCargo;

        entry transferCargo when counter > 0 is
        begin
            counter := counter - 1;
            Printer.Print("Cargo transfered -> Warehouse counter : " & Positive'image(counter));
        end transferCargo;
    end Warehouse;

    


    -- 
    task type Shop(Id: Natural) is
        entry notification;
        entry sellCargo(itemSold : out Boolean);
        entry close; 
    end Shop;

    task body Shop is 
        stock : Natural := 0;
        sold : Natural := 0;
        opened : Boolean := True;
    begin
        while opened loop 
            select 
                accept notification do
                    Warehouse.transferCargo;
                    stock := stock + 1;
                    Printer.Print("Shop" & Id'image &" received cargo -> stock : " & Positive'image(stock));
                end notification;
            or
                accept sellCargo(itemSold : out Boolean) do
                    delay 0.2;
                    if stock = 0 then
                        Printer.Print("Stock of Shop" & Id'image & " is empty!");
                        itemSold := False;
                    else
                        stock := stock - 1;
                        sold := sold + 1;
                        Printer.Print("Shop sold cargo -> stock :" & Positive'image(stock));
                        itemSold := True;
                    end if;
                end sellCargo;
            or 
                accept close;
                    opened := False;
                    Printer.Print("Shop" & Id'Image & " closed!   ->   Sold :" & Positive'image(sold) & ", Stock :" & Positive'image(stock));
                    exit;
            end select;
        end loop;
    end Shop;

    type Shoop_Access is access Shop;
    type TShops is array(Natural range<>) of Shoop_Access;
    type TShops_access is access TShops;
    Shops_Array : TShops_access := new TShops(0..4);

    -- 
    task deliveryTruck;
    --  type deliveryTruck_Access is access deliveryTruck;

    task body deliveryTruck is
        randomNumber : Natural := 0;
    begin
        Reset(G);
        delay 0.1;
        Warehouse.storeCargo;
        randomNumber := Random(G) rem 5;
        select
            Shops_Array(randomNumber).all.notification;
        or
            delay 0.01;
            Printer.Print("Delivery truck could not notify the Shop!");
        end select;
        Printer.Print("Delivery truck finished!");
    end deliveryTruck;

    
    --
    task type Buyer(Shops_Array : TShops_access; Id: Natural);
    type Buyer_Access is access Buyer;

    task body Buyer is
        randomNumber : Natural := 0;
        itemBought : Boolean := False;
    begin 
        Reset(G);
        Printer.Print("Buyer" & Id'image & " generated!");

        Printer.Print("Buyer" & Id'image & " is chosing a shop...");
        delay 0.4;
        randomNumber := Random(G) rem 5;
        Printer.Print("Buyer" & Id'image & " chose and enters the shop" & randomNumber'image & " and browse through the shop before buying one item...");
        delay 0.1;

        Shops_Array(randomNumber).sellCargo(itemBought);
        if itemBought then
            Printer.Print("Buyer" & Id'image & " bought an item on the shop" & randomNumber'image & " and leaves the shop.");
        else 
            Printer.Print("Buyer" & Id'image & " could not buy an item on the shop" & randomNumber'image & " and leaves the shop.");
        end if;
    end Buyer;


    --
    task Scheduler;
    task body Scheduler is 
        startTime : Time := Clock;
        currentTime : Time;
        generatedBuyer : Buyer_Access; 
        buyersCount : Natural := 0;
    begin 

        loop
            currentTime := Clock;
            buyersCount := buyersCount + 1;
            generatedBuyer := new Buyer(Shops_Array, buyersCount);
            delay 0.3;
            exit when ada.Real_Time.To_Duration(currentTime - startTime) > 10.0;
        end loop;

        for i in Shops_Array'range loop
                Shops_Array(i).close;
        end loop;

        delay 3.0;
        Printer.Print("End of simulation!");
    end Scheduler;
    
begin
    for i in Shops_Array'range loop
        Shops_Array(i) := new Shop(i);
    end loop;
end Demo;