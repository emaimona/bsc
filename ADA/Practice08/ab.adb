with ada.text_io; use ada.text_io;
procedure  AB is
    task A;
    task B;

    task body A is
    begin 
        for I in 1..Positive'Last loop
            Put_line("A: " & Positive'Image(I));
        end loop;
    end A;

    task body B is
    begin
         for I in 1..Positive'Last loop
            Put_line("B: " & Positive'Image(I));
        end loop;
    end B;

    begin
        null;
    end AB;