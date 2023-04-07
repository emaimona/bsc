
with Ada.Strings.Unbounded;

generic
   type Index is (<>);
   type Elem is private;

package PManifest is
  
   type FuelLevel is new Float range 0.0 .. 100.0;
   type CargoArray is array(Index range <>) of Elem;
   type StringLiteral is new Ada.Strings.Unbounded.Unbounded_String;

   type Manifest(Max: Index) is limited private;

   procedure addCargo(c : in Elem; m : in out Manifest);
   procedure addSeveralCargo(carray : CargoArray; m : in out Manifest);
   procedure buyFuel(fuelAmount : in FuelLevel; fuelPrice : in Float; m : in out Manifest; isPosible : out Boolean);
   procedure recordTrip(origin : in StringLiteral; destination : in StringLiteral; Speed : in Float; m : in out Manifest);
   procedure createManifest(name : in StringLiteral; fuel : in FuelLevel; revenue : in Float; m : in out Manifest);
   procedure printManifestJSON(m : in Manifest);
   
   generic
      with function getCost(item : Elem) return Float;
      with function getDestination(item : Elem) return StringLiteral;
   procedure unloadCargo(destination: StringLiteral; m : in out Manifest);


   generic
      with procedure operation(el: Elem);
   procedure ForEach(m : in out Manifest);

private
   type Manifest(Max: Index) is record
      Name : StringLiteral;
      Cargo : CargoArray(Index'First..Max);
      Fuel : FuelLevel := 0.0;
      Revenue : Float := 0.0;
      Pointer : Index := Index'First;
   end record;
end PManifest;
