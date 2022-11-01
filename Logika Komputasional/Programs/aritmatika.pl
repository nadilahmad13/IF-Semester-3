/* FAKTA */
/* suksesor(X,Y) benar, jika Y
adalah suksesor dari X */
suksesor(0,1).
suksesor(1,2).
suksesor(2,3).
suksesor(3,4).

/* ATURAN */
/* max2(X,Y,Z) benar, jika Z
adalah nilai maksimum dari 2
bilangan X dan Y */
max2(X,Y,X) :- X >= Y.
max2(X,Y,Y) :- X < Y.

/* FAKTA DAN ATURAN */
/* plus(X,Y,Z) benar, jika Z
adalah hasil penjumlahan dari X
dan Y */
/* Basis */
plus(0,X,X).
/* Rekurens */
plus(X,Y,Z) :- suksesor(V,X),
plus(V,Y,W),
suksesor(W,Z).