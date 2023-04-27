with Ada.Text_IO, Ada.Strings.Unbounded, Pcontainer, PManifest;
use Ada.Text_IO, Ada.Strings.Unbounded, PContainer;

procedure demo is
    type Index is new Positive range 1..100;

    cargo1 : Container;
    cargo2 : Container;
    cargo3 : Container;
    cargo4 : Container;
    cargo5 : Container;
    c_country1 : StringLiteral := To_Unbounded_String("Angola");
    c_country2 : StringLiteral := To_Unbounded_String("Hungary");
    c_country3 : StringLiteral := To_Unbounded_String("Russia");

    package IManifest is new PManifest(Index, Container);

    -- generic functions
    procedure printAllCargos is new IManifest.ForEach(printJSON);
    function HasCargoDestination( c: Container; destination : IManifest.StringLiteral) return Boolean is
    begin
        return PContainer.getDestination(c) = StringLiteral(destination);
    end HasCargoDestination;
    procedure unloadCargoManifest is new IManifest.unloadCargo(getCost, HasCargoDestination);

    manifest : IManifest.Manifest(10);
    name_manifest : IManifest.StringLiteral := IManifest.To_Unbounded_String("Ada Manifest");

    m_country1 : IManifest.StringLiteral := IManifest.To_Unbounded_String("Angola");
    m_country2 : IManifest.StringLiteral := IManifest.To_Unbounded_String("Hungary");
    m_country3 : IManifest.StringLiteral := IManifest.To_Unbounded_String("Russia");
begin
    New_line;
    -- Creating Cargos
    NewContainer(c_country3, c_country1, DHL, True,  cargo1);
    NewContainer(c_country3, c_country2, Maersk, False,  cargo2);
    NewContainer(c_country1, c_country3, PIL, True,  cargo3);
    NewContainer(c_country2, c_country1, MSC, True,  cargo4);
    NewContainer(c_country1, c_country2, CosCo, True,  cargo5);


    -- Testin Container methods
    Put_Line("===== Printing the container1 ======");
    printJSON(cargo1);
    New_Line;
    Put_Line("===== Printing the container1 after modifying cost ======");
    modifyCost(cargo1, 12.0);
    printJSON(cargo1);


    -- Createing manifest
    New_line;
    New_line;
    Put_Line("===== Creating manifest ======");
    IManifest.createManifest(name_manifest, 12.0, 0.0, manifest);
    IManifest.printManifestJSON(manifest);


     -- Adding cargos
    New_line;
    New_line;
    IManifest.addSeveralCargo((cargo1, cargo2, cargo3, cargo4, cargo5), manifest);
    Put_Line("===== Printing all Cargos ======");
    printAllCargos(manifest);

    -- Print the manifest
    New_line;
    Put_Line("===== Printing the manifest ======");
    IManifest.printManifestJSON(manifest);

    -- unloading cargo
    New_line;
    New_line;
    Put_Line("Unloading cargos for " & IManifest.To_String(m_country1));
    unloadCargoManifest(m_country1, manifest);
    Put_Line("===== Printing all Cargos ======");
    printAllCargos(manifest);


    -- Print the manifest
    New_line;
    Put_Line("===== Printing the manifest after unloading ======");
    IManifest.printManifestJSON(manifest);

    -- Buying Fuel
    New_Line;
    declare
        isPossible : Boolean:= false;
        fuel : IManifest.FuelLevel := 80.0;
        price : Float := 1.2;
    begin
        New_Line;
        IManifest.buyFuel(fuel, price, manifest, isPossible);
        Put_Line("Was it Possible to buy fuel? " & Boolean'Image(isPossible));
        IManifest.printManifestJSON(manifest);

        New_Line;
        New_Line;
        fuel := 40.0;
        IManifest.buyFuel(fuel, price, manifest, isPossible);
        Put_Line("Was it Possible to buy fuel? " & Boolean'Image(isPossible));
        IManifest.printManifestJSON(manifest);
    end;
    New_Line;
    New_Line;

    -- Recording trip
    Put_Line("Recording the trip at 0.007 of Speed");
    IManifest.recordTrip(m_country1, m_country2, 0.07, manifest);

    Put_Line("Recording the trip at 30.0 of Speed");
    IManifest.recordTrip(m_country1, m_country2, 30.0, manifest);
    IManifest.printManifestJSON(manifest);
    New_Line;
    New_Line;


    Put_Line("===== Printing all Cargos ======");
    printAllCargos(manifest);



end demo;