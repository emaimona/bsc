with ada.Text_IO, hauntedhouse;
use ada.Text_IO, hauntedhouse;

procedure demo is 
    task Princess is 
        entry getScared(ghostPos : Position);
    end Princess;

    type durationPtr is access Duration;
    task type Ghost(dur : durationPtr);

    task type wizard(nbr : Positive; dur : durationPtr);

    task body Princess is 
        lives : Natural := 3;
        pos : Position := (1, 3);
    begin
        while lives > 0 loop
            select
                accept getScared(ghostPos : Position) do
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
            select
                Princess.getScared(GetRandPos);
                Put_line("Scare the princess");
                delay 0.2;
            or
                delay dur.all;
                exit;
            end select;
        end loop;
    end Ghost;


    type ghostPtr is access Ghost;

    task body wizard is
        nbrOfGhosts : Natural := nbr;
        randomGhost : ghostPtr;
    begin

        while nbrOfGhosts > 0 loop
            Put_line("Ghost created");
            randomGhost := new Ghost(dur);
            nbrOfGhosts := nbrOfGhosts - 1;
        end loop;
    end wizard;

    type wizardPtr is access wizard;

    wizz : wizardPtr;
    dur : durationPtr;
begin
    dur := new duration;
    dur.all := 0.1;
    wizz := new wizard(2, dur);
end demo;