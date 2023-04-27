with Ada.Numerics.Discrete_Random, Ada.Integer_Text_IO, Ada.Text_IO, ada.Containers.Generic_Array_Sort;
use Ada.Integer_Text_IO, Ada.Text_IO;

package body PElection is
    package Random_int is new Ada.Numerics.Discrete_Random (Integer);
    G : Random_int.Generator;

    procedure Initialize_Regional_Votes (E : in out Election) is
        val : Integer := 0;
    begin
        Random_int.Reset(G);
        for i in reverse E.Regional_Votes'range(1) loop
            for j in E.Regional_Votes'range(2) loop
                E.Regional_Votes(i,j) := Random_int.Random(G, 1, 5);
            end loop;
        end loop;
    end Initialize_Regional_Votes;


    procedure Finalize_Votes (E : in out Election) is
        count : Integer := 0;
        r : Natural := 0;
    begin 
        for p in E.Final_Votes'Range loop
            for i in E.Regional_Votes'range(1) loop
                for j in E.Regional_Votes'range(2) loop
                    if p = j then
                        count := count + E.Regional_Votes(i,j);
                        r := r + 1;
                    end if;
                end loop;
            end loop;
             E.Final_Votes(p) := count * r;
        end loop;
    end Finalize_Votes;


    function Final_Vote_Of_Candidate(E : Election; C : Candidates) return Integer is
    begin
        return E.Final_Votes(C);
    end Final_Vote_Of_Candidate;


    function Regional_Vote_Of_Candidate(E : Election; R : Regions; C : Candidates) return Integer is
    begin
        return E.Regional_Votes(R, C);
    end Regional_Vote_Of_Candidate;




    --- 3
    function Find_First_Place (E : Election) return Candidates is
        c : Candidates;
        max : Integer := Integer'first;
    begin

        for i in E.Final_Votes'Range loop
            if E.Final_Votes(i) > max then
                c := i;
                max := E.final_Votes(i);
            end if;
        end loop;
        return c;
    end Find_First_Place;


    function Find_Last_Place (E : Election) return Candidates is
        c : Candidates;
        max : Integer := Integer'last;
    begin

        for i in E.Final_Votes'Range loop
            if E.Final_Votes(i) < max then
                c := i;
                max := E.final_Votes(i);
            end if;
        end loop;
        return c;
    end Find_Last_Place;


    function Find_N_th_Place (E : Election; N : Integer) return Candidates is
        arr : EArray := E.Final_Votes;
        procedure sort is new Ada.Containers.Generic_Array_Sort(Candidates, Integer, EArray);
    begin
        sort(arr);

        if N < 0 then
            return E.Final_Votes'last;
        elsif N > E.final_Votes'last'enum_rep then
            return E.Final_Votes'first;
        else
            return Candidates'val(N-1);
        end if;
    end find_N_th_Place;

    function compare_Candidates(E : Election; C1 : Candidates; C2 : Candidates) return Boolean is
    begin
        return E.Final_Votes(c1) > E.Final_Votes(c2);
    end compare_Candidates;




    -- GRADE 4

    --  function Calculate_Percentage_Of_Candidate (E : Election; C : Candidates) return Float is
    --  begin


    --  end Calculate_Percentage_Of_Candidate;
    --  function Calculate_Regional_Percentage_Of_Candidate (E : Election; R : Regions; C : Candidates) return Float;
    --  procedure Print (E : Election; B : Boolean := True);

end PElection;