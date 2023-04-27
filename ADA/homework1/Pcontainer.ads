with Ada.Strings.Unbounded;

package PContainer is 
    Type TCompany is (DHL, Maersk, Cosco, PIL, MSC); 
    for TCompany use (5, 8, 11, 15, 17); 

    type Container is private;
    type StringLiteral is new Ada.Strings.Unbounded.Unbounded_String;

    -- Getters
    function getDestination(c : in Container) return StringLiteral;
    function getSendingCompany(c : in Container) return TCompany;
    function getCost(c : in Container) return Float;

    --  Setters
    procedure setCost(c : in out Container; cost : in Float);
    -- Methods

    procedure modifyCost(c : in out Container; amount : in Float);
    function calculateDistance(destination : in StringLiteral; loaded_at : in StringLiteral) return Integer;
    procedure printJSON(c : in Container);

    procedure NewContainer(loaded_at: in StringLiteral; destination : in StringLiteral; sendingCompany : in TCompany; isPremium : in Boolean; c : out Container);

private
    type Container is record
        Destination : StringLiteral;
        SendingCompany : TCompany;
        Cost : Float;
        isPremium: Boolean;
    end record;
end PContainer;
