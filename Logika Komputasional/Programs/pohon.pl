/* FAKTA */
/* pria(X) benar, jika X adalah pria */
    pria(philip).
    pria(charles).
    pria(williams).

/* ayah(X,Y) benar, jika X adalah ayah dari Y */
    ayah(philip, charles).
    ayah(charles, williams).
    ayah(charles, harry).

/* ATURAN */
/* anakLelaki(X,Y) benar, jika Y adalah ayah dari X dan X adalah pria dan
X tidak sama dengan Y */
    anakLelaki(X,Y) :- ayah(Y,X), pria(X), X \= Y.