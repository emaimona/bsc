with ada.text_io, ada.integer_text_io;
use ada.text_io, ada.integer_text_io;

procedure demo is 
   type d is range 1..10;
   val : Boolean := true;
   x : Integer := 4;
   s : string := "hello";
   

   type Month_Type is (Jan, Febr, Mar, Apr, May, June, July, Aug, Sept, Oct,
Nov, Dec);
type Date is record
Day : Integer range 1 .. 31;
Month : Month_Type;
Year : Integer range 1 .. 3000;
end record;
Ada_Birthday : Date := (10, Dec, 1815);
mid_term : Date := (Day => 21, Year => 2020, Month => Oct);
My_birthday : Date := (Year => 1999, others => <> );
begin
   for i in 1..x loop
      put("k ");
      x := 3;
   end loop;

   put(My_birthday.day'image);
end demo;