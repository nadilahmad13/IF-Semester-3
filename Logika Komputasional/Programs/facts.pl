/*Tes Facts*/
kotak(spongebob).
kuning(spongebob).
teman(patrick,spongebob).
teman(X,Y) :- teman(Y,X).
spons(X) :- kotak(X), kuning(X).
ayah(berta,philips).