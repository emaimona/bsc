with Ada.Text_IO;
use Ada.Text_IO;

package body PManifest is
   

    procedure addCargo(c : in Elem; m : in out Manifest) is 
    begin
        if m.Pointer /= Index'Succ(m.Cargo'Last) then
            m.Cargo(m.Pointer) := c;
            m.Pointer := Index'succ(m.Pointer);
        end if;
    end addCargo;

    procedure addSeveralCargo(carray : CargoArray; m : in out Manifest) is
    begin
        for i in carray'Range loop
            addCargo(carray(i), m);
        end loop;
    end addSeveralCargo;

    procedure buyFuel(fuelAmount : in FuelLevel; fuelPrice : in Float; m : in out Manifest; isPosible : out Boolean) is 
        money : Float;
    begin
        money := Float(fuelAmount) * fuelPrice;
        if m.Revenue - money >= 0.0 then
            isPosible := true;
            m.Revenue := m.Revenue - money;

            if m.Fuel + fuelAmount > FuelLevel'Last then
                m.Fuel := FuelLevel'Last;
            else
                m.Fuel := (m.Fuel + fuelAmount);
            end if;
        else
            isPosible := false;
        end if;
    end buyFuel;

    -- Out to calculate the time
    procedure recordTrip(origin : in StringLiteral; destination : in StringLiteral; Speed : in Float; m : in out Manifest) is 
        fuelUsed : Float;
    begin
        fuelUsed := Float(m.Fuel) - abs(Float(Length(origin) - Length(destination)) / speed * 2.0);

        if fuelUsed <= 0.0 then
            m.Fuel := FuelLevel'first;
        else
            m.Fuel := FuelLevel(fuelUsed);
        end if;
    end recordTrip;


    procedure createManifest(name : in StringLiteral; fuel : in FuelLevel; revenue : in Float; m : in out Manifest) is
    begin
        m.Name := name;
        m.Fuel := fuel;
        m.Revenue := revenue;
    end createManifest;

    procedure printManifestJSON(m : in Manifest) is
    begin
        Put("{""Name"": " & To_string(m.Name) & ", ""Fuel"": " & FuelLevel'Image(m.Fuel) & ", ""Revenue"": " & Float'Image(m.Revenue) & "}");
    end printManifestJSON;
   

   procedure unloadCargo(destination: StringLiteral; m : in out Manifest) is 
   begin
        for i in m.Cargo'Range loop
            if getDestination(m.Cargo(i)) = destination then
                m.Revenue := m.Revenue + getCost(m.Cargo(i));
                if Index'succ(i) /= m.Pointer then
                    for j in Index'succ(i)..m.Pointer loop
                        m.Cargo(Index'Pred(j)) := m.Cargo(j);
                    end loop;
                end if;
                m.Pointer := Index'Pred(m.Pointer);
            end if;
        end loop;
   end unloadCargo;

    procedure ForEach(m : in out Manifest) is
    begin
        for i in Index'first..Index'pred(m.Pointer) loop
            operation(m.Cargo(i));
        end loop;
    end ForEach;
end PManifest;
