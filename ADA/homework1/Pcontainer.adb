
with Ada.Text_IO;
use Ada.Text_IO;

package body PContainer is
    -- Getters
    function getDestination(c : in Container) return StringLiteral  is
    begin
        return c.Destination;
    end getDestination;

    function getSendingCompany(c : in Container) return TCompany is
    begin
        return c.SendingCompany;
    end getSendingCompany;

    function getCost(c : in Container) return Float is
    begin
        return c.Cost;
    end getCost;



    --  Setters
    procedure setCost(c : in out Container; cost : in Float) is
    begin
        c.Cost := cost;
    end setCost;




    -- Methods 
    procedure modifyCost(c : in out Container; amount : in Float) is
    begin
        c.Cost := c.Cost + amount;
    end modifyCost;



    function calculateDistance(destination : StringLiteral; loaded_at : in StringLiteral) return Integer is
    begin    
        return abs( Length(destination) - Length(loaded_at));
    end calculateDistance;



    procedure printJSON(c : in Container) is 
    begin

        Put("{""Destination"": " & To_string(c.Destination));
        Put(", ""Origin"": " & c.SendingCompany'Image & ", ""Cost"": " & Float'Image(c.Cost) & ", ""IsPremium"": " & Boolean'Image(c.isPremium) & "}");
        New_Line;
    end printJSON;


    procedure NewContainer(loaded_at : in StringLiteral; destination : StringLiteral; sendingCompany : TCompany; isPremium : Boolean; c : out Container) is 
        distance : Integer;
        premium : Float;
        value : Float := Float(sendingCompany'Enum_rep);
    begin
        if isPremium then premium := 1.0; else premium := 0.0; end if;
        distance := calculateDistance(destination, loaded_at);

        c.Cost := value * 1.0/6.0+ Float(distance) * 5.0 + premium*3.0;
        c.destination := destination;
        c.SendingCompany := sendingCompany;
        c.isPremium := isPremium;
    end NewContainer;
end PContainer;
