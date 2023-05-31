with ada.Text_IO, ada.numerics.Float_Random, ada.Numerics.Discrete_Random, ada.Real_Time;
use Ada.Text_io, ada.Numerics.Float_Random, ada.Real_Time;


 -- Ada Programming mid-term, 2023. MAY 24. COPY THIS TEXT TO EVERY MARK

-- This solution was submitted and prepared by

-- <Maimona Emanuel Nzinga, GAU5OE> for the mid-term of the Ada Programming course.

--  I declare that this solution is my own work.

--  I have not copied or used third-party solutions.

--  I have not passed my solution to my classmates, neither made it public.

procedure Main4 is
   package Prandom is new ada.Numerics.Discrete_Random(Natural);

   protected Printer is
      procedure Print(s: String);
   end Printer;

    protected body Printer is
      procedure Print(s: in String) is
      begin
         Put_line(s);
      end Print;
   end Printer;




   protected SafeRandom is
      procedure DInit;
      procedure FInit;
      function FGenerate return float;
       function DGenerate return Natural;
   private
      GF: Generator;
      GD: Prandom.Generator;
   end SafeRandom;

    protected body SafeRandom is
      procedure FInit is
      begin
         Reset(GF);
      end FInit;

       procedure DInit is
      begin
         Prandom.Reset(GD);
      end DInit;


      function FGenerate return float is
      begin
         return Random(GF);
      end FGenerate;

      function DGenerate return Natural is
      begin
         return Prandom.Random(GD);
      end DGenerate;

      end SafeRandom;


      task type Casino is
         entry enter;
   end Casino;

   type PCasino is access Casino;
   Tcasino : array(1..3) of PCasino;

   task body Casino is
      counter : Natural := 0;
      start : Time := Clock;
   begin
         delay Duration(SafeRandom.Fgenerate);
         Printer.Print("Casino: opened");
          loop
            select
            when counter <= 5 => accept enter;
               counter:= counter + 1;

                Printer.Print("Casino: a player got in");
         or

            delay 1.0;
            end select;

            exit when To_Duration(clock - start) > 15.0;
         end loop;
         Printer.Print("Casino: finished");
      end Casino;



   task type Player(name : access String);
   type Pplayer is access Player;

   task body Player is
      rand : Natural := 0;
      points : Natural := 0;
      score : Natural := 0;
      went : Boolean := false;
         begin
            delay Duration(SafeRandom.Fgenerate);
      Printer.Print("player " & name.all & " : arrived");
      rand := (SafeRandom.DGenerate mod 3) + 1;

      for i in 1..2 loop
         if (SafeRandom.DGenerate mod 2) = 0 then


            select
               Tcasino(rand).enter;
                rand := SafeRandom.DGenerate rem 3 + 1;
               points := SafeRandom.DGenerate rem 1001;

               Printer.Print("player " & name.all & " got in casino: " & rand'image & " score: " & points'image);
               score := score + points;
               went := True;
               exit;
             else
                  Printer.Print("player " & name.all & " failed to enter");
         end select;
            end if;
      end loop;
      if went then
          Printer.Print("player " & name.all & " did not play");
         end if;
            Printer.Print("player " & name.all & " finished");
            end Player;



   Tplayers : array(1..20) of PPlayer;

   dummy: PPlayer;

begin
   SafeRandom.FInit;
   SafeRandom.DInit;

   Printer.Print("Game started");

   for i in Tcasino'range loop
      Tcasino(i) := new Casino;
   end loop;


   for i in Tplayers'range loop
      dummy := new Player(new String'(i'image));
      delay 0.5;
   end loop;



end Main4;























