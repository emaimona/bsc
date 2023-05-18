with ada.text_io;
use ada.text_io;

procedure demo is 
    GONE : exception;

    task type chicken is 
        entry play;
        entry feed;
    end chicken;
    type chickenPtr is access Chicken;

    task type child(ch : ChickenPtr);

    type childPtr is access Child;

    task body chicken is 
        nr : Natural := 4;
    begin
        accept play;
        while nr > 0 and nr < 30 loop 
            select 
                accept feed do
                    nr := nr + 1;
                    Put_line("Chicken feeded! Stomach " & nr'image);
                    if nr >= 30 then
                        raise GONE;
                    end if;
                end feed;
            or
                delay (1.0);
                nr := nr - 1;
                if nr = 0 then
                    Put_line("The Chicken died!");
                end if;
            end select;

        end loop;
            
    end chicken;


    task body child is 
    begin
        loop
            ch.feed;
            delay 0.1;
        end loop;

        exception
            when GONE => Put_line("The chicken flew away!");
            when Tasking_Error => Put("The Child died of sorrow!");

    end child;

    mychicken : chickenPtr;
    kid : childPtr;
begin
    mychicken := new chicken;
    mychicken.play;

    kid := new child(mychicken);
exception
        when GONE => Put_line("The chicken flew away!");
        when Tasking_Error => Put("The Child died of sorrow!");
end demo;