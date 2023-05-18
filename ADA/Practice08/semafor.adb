with ada.text_io; use ada.text_io;


procedure semafor is

    task type Print is
        entry Init (S: String := " ");
    end Print;

    a, b : Print;

    task Semaf is 
        entry P;
        entry V;
    end Semaf;


    task body Semaf is 
    begin
        loop 
            accept P;
            accept V;
        end loop;
    end Semaf;


    task body Print is
        type PStr is access String;
        name: PStr;
    begin
        accept Init (S: String := " ") do
            name := new String(1..S'Length);
            name.all := s;
        end Init;
        for I in 1..Positive'Last loop
            Semaf.P;
            Put_line(name.all & Positive'Image(I));
            Semaf.V;
        end loop;
    end Print;
begin 
    null;
    a.Init("John");
    b.Init("Mary");
end semafor;