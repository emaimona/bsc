with ada.Text_IO, PElection;
use ada.Text_IO;


procedure Demo is
    type Candidates is (Rasul, Bill, Jill, Will, Nill);
    type Regions is (Budapest, Pecs, Gyor, Debrecen, Szeged);

    package IElection is new PElection(Candidates, Regions);
    

    -- VAriables
    E : IElection.Election(5);


    -- Testing functions
    procedure PrintFinalVotes is 
    begin
        for i in Candidates'Range loop
            Put_line("Final votes of " & i'Image & " is " & IElection.Final_Vote_Of_Candidate(E, i)'Image);
        end loop;
    end PrintFinalVotes;

    procedure PrintRegionalVotes is
    begin  
        for r in Regions'Range loop
            Put_line(r'Image);
            for c in Candidates'range loop
                Put_line("   " & c'Image & " is " & IElection.Regional_Vote_Of_Candidate(E, r, c)'Image);
            end loop;
            New_Line;
        end loop;

    end PrintRegionalVotes;

    type arri is array(Positive range <>) of Integer;
    type a is record 
        t: arri(1..4);
    end record;

    v : arri := (1,2,3,4);
    x : a(v);
begin
    IElection.Initialize_Regional_Votes(E);
    IElection.Finalize_Votes(E);

    --  New_Line;
    --  PrintFinalVotes;
    --  New_Line;

    --  PrintRegionalVotes;



    -- GRADE 3

    --  Put_line("The first place is : " & IElection.Find_First_Place(E)'Image);
    --  Put_line("The last place is : " & IElection.Find_Last_Place(E)'Image);
    --  Put_line("The 3nd place is : " & IElection.Find_N_th_Place(E, 3)'image);
    --  Put_line("Is Rasul greate than JiLL: " & IElection.compare_Candidates(E, Rasul, Jill)'Image);


    -- GRADE 4



end Demo;