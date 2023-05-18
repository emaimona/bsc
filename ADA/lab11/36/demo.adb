with ada.Text_IO, hauntedhouse;
use ada.Text_IO, hauntedhouse;

procedure demo is 
    task Princess is 
        entry getScared(ghostPos : Position);
    end Princess;

    task Ghost;


    task body Princess is 
        lives : Natural := 3;
        pos : Position := (1, 3);
    begin
        while lives > 0 loop
            select
                accept getScared(ghostPos : Position) do
                    Put_line("Scare the princess");

                    if ghostPos = pos then
                        lives := lives - 1;
                        Put_line("Princess scaried, life : " & lives'image);
                    end if;
                end getScared;
            or 
                terminate;
            end select;
        end loop;
    end Princess;

    task body Ghost is
    begin
        while Princess'Callable loop
            Princess.getScared(GetRandPos);
            delay 0.2;
        end loop;
    end Ghost;
begin
    null;
end demo;