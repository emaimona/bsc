with ada.Text_IO, ada.numerics.Float_Random;
use Ada.Text_io, ada.Numerics.Float_Random;


 -- Ada Programming mid-term, 2023. MAY 24. COPY THIS TEXT TO EVERY MARK

-- This solution was submitted and prepared by

-- <Maimona Emanuel Nzinga, GAU5OE> for the mid-term of the Ada Programming course.

--  I declare that this solution is my own work.

--  I have not copied or used third-party solutions.

--  I have not passed my solution to my classmates, neither made it public.

procedure Main2 is

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
      procedure Init;
      function Generate return float;
   private
      G: Generator;
   end SafeRandom;

    protected body SafeRandom is
      procedure Init is
      begin
         Reset(G);
      end Init;


      function Generate return float is
      begin
         return Random(G);
      end Generate;
      end SafeRandom;


      task Casino is
         entry enter;
      end Casino;


      task body Casino is
      begin
         delay Duration(SafeRandom.generate);
         Printer.Print("Casino: opened");
         loop
            select
               accept enter;
                Printer.Print("Casino: a player got in");
         or

            terminate;
          end select;
         end loop;
         Printer.Print("Casino: finished");
      end Casino;



         task Player;

         task body Player is
         begin
            delay Duration(SafeRandom.generate);
            Printer.Print("player: arrived");
            for i in 1..3 loop
               select
                  Casino.enter;
                  Printer.Print("player: got in");
                  exit;
               else
                  Printer.Print("player: failed to enter");
         end select;
         if i /= 3 then
            Printer.Print("player: try again");
            end if;
               end loop;
            Printer.Print("player: finished");
            end Player;




begin
   SafeRandom.Init;

            Printer.Print("Game started");
end Main2;
