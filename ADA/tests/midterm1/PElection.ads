

generic
    type Candidates is (<>);
    type Regions is (<>);

package PElection is
    type Election(Count: Integer) is limited private;

    procedure Initialize_Regional_Votes (E : in out Election);
    procedure Finalize_Votes (E : in out Election);
    function Final_Vote_Of_Candidate(E : Election; C : Candidates) return Integer;
    function Regional_Vote_Of_Candidate(E : Election; R : Regions; C : Candidates) return Integer;

    -- 3
    function Find_First_Place (E : Election) return Candidates;
    function Find_Last_Place (E : Election) return Candidates;
    function Find_N_th_Place (E : Election; N : Integer) return Candidates;
    function compare_Candidates (E : Election; C1 : Candidates; C2 : Candidates) return Boolean;


    --
    --  function Calculate_Percentage_Of_Candidate (E : Election; C : Candidates) return Float;
    --  function Calculate_Regional_Percentage_Of_Candidate (E : Election; R : Regions; C : Candidates) return Float;
    --  procedure Print (E : Election; B : Boolean := True);

private
    type EMatrix is array(Regions range<>, Candidates range<>) of Integer;
    type EArray is array(Candidates range<>) of Integer;
type Election(Count: Integer) is record
    Regional_Votes : EMatrix(Regions'First..Regions'last, Candidates'first..Candidates'last);
    Final_Votes : EArray(Candidates'first..Candidates'last) := (others => 0);
    Nbr_Candidates : Integer := Count;
end record;
end PElection;