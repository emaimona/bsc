(* Mathematical Logic second midterm
   computer exercises

Your Name:Maimona Emanuel Nzinga

Your Neptun code: SVBIIC

When the time is over, send it by email to

bodri.mh3@gmail.com

*)


Require Import Classical.

Parameters P Q R S E U W: Prop.

Section exercise1a.
Hypothesis pr1: P /\ (Q /\ R).
Hypothesis pr2: (S /\ E) /\ U.
Hypothesis pr3: E -> W.
Goal (Q /\ P) /\ W.

(*Write your solution here.*)
pose proof(proj1 pr2).
pose proof(proj2 H).
pose proof(pr3 H0).
pose proof(proj1 pr1).
pose proof(proj2 pr1).
pose proof(proj1 H3).
pose proof(conj H4 H2).
pose proof(conj H5 H1).
exact H6.
Qed.
End exercise1a.

Section exercise1b.
Hypothesis pr1: Q.
Hypothesis pr2: Q->P \/ R.
Hypothesis pr3: R->S.
Goal P\/S.

(*Write your solution here.*)
pose proof(pr2 pr1).
destruct H.
pose proof(or_introl (B:=S) H).
exact H0.
pose proof(pr3 H).
pose proof(or_intror (A:=P) H0).
exact H1.
Qed.
End exercise1b.


Section exercise1c.
Hypothesis pr1: S->P.
Hypothesis pr2: Q -> E.
Goal (P->Q) -> (S->E).

(*Write your solution here.*)
intros.
pose proof(pr1 H0).
pose proof(H H1).
pose proof(pr2 H2).
exact H3.
Qed.
End exercise1c.

(*Bonus question, if you have a lot of time*)
Section exercise1d.

Hypothesis pr1: (P \/ ~ Q) <-> (R /\ S ).
Hypothesis pr2: E /\ (E -> S ).
Hypothesis pr3: Q.
Goal R -> P.

(*Write your solution here.*)
unfold not in *.
unfold iff in *.
destruct pr1.
destruct pr2.
pose proof(H2 H1).
intros.
pose proof(conj H4 H3).
pose proof(H0 H5).
destruct H6.
exact H6.
contradiction.
End exercise1d.




(* Thanks a lot for your time and effort 🇦🇴️*)

























