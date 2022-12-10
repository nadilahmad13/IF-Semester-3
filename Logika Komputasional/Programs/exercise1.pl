/* FAKTA */
ibu(emy,charles).
ibu(emy,david).
ibu(emy,randy).
ibu(maria,fara).

/* ATURAN */
saudara_kandung(Anak1, Anak2) :- ibu(Ibu,Anak1), ibu(Ibu, Anak2).

append([],X,X) :- !.
append([A|B],C,[A|D]) :- append(B,C,D).