/* BAGIAN I: Fakta, Rule, dan Query */
/* Deklarasi Fakta */
/* pria(X) : X adalah pria */
pria(gede).
pria(gojo).
pria(vonNeumann).
pria(vanRossum).
pria(bambang).
pria(vito).
pria(ave).
pria(wesly).
pria(elonMusk).
pria(patrick).

/* wanita(X) : X adalah wanita */
wanita(indah).
wanita(lovelace).
wanita(khelli).
wanita(power).
wanita(aqua).
wanita(wulandari).
wanita(anya).

/* usia(X,Y) : X berusia Y */
usia(gede, 96).
usia(indah, 92).
usia(gojo, 90).
usia(lovelace, 79).
usia(khelli, 89).
usia(vonNeumann, 92).
usia(vanRossum, 65).
usia(bambang, 60).
usia(vito, 56).
usia(power, 50).
usia(ave, 54).
usia(aqua, 50).
usia(wulandari, 24).
usia(wesly, 26).
usia(elonMusk, 28).
usia(patrick,24).
usia(anya, 4).

/* menikah(X,Y) : X menikah dengan Y */
menikah(gede, indah).
menikah(indah, gede).
menikah(gojo, lovelace).
menikah(lovelace, gojo).
menikah(khelli, vonNeumann).
menikah(vonNeumann, khelli).
menikah(vito,power).
menikah(power,vito).
menikah(ave, aqua).
menikah(aqua, ave).
menikah(wesly, wulandari).
menikah(wulandari, wesly).

/* anak(X,Y) : X adalah anak Y */
anak(vanRossum, gede).
anak(vanRossum, indah).
anak(bambang, gede).
anak(bambang, indah).
anak(vito, gede).
anak(vito, indah).
anak(power, gojo).
anak(power, lovelace).
anak(ave, gojo).
anak(ave, lovelace).
anak(aqua, khelli).
anak(aqua, vonNeumann).
anak(wesly, vito).
anak(wesly, power).
anak(anya, wesly).
anak(anya, wulandari).
anak(elonMusk, ave).
anak(elonMusk, aqua).
anak(patrick, ave).
anak(patrick, aqua).

/*saudara(X,Y) : X adalah saudara kandung Y*/
saudara(vanRossum, bambang).
saudara(bambang, vanRossum).
saudara(vanRossum, vito).
saudara(vito, vanRossum).
saudara(bambang, vito).
saudara(vito, bambang).
saudara(power, ave).
saudara(ave, power).
saudara(elonMusk, patrick).
saudara(patrick, elonMusk).

/* Deklarasi Rules */
% kakak(X,Y) : X adalah kakak dari Y (baik perempuan maupun lelaki)
kakak(X,Y) :- 
    saudara(X,Y),
    usia(X,U),
    usia(Y,V),
    U>V.

% keponakan(X,Y) : X adalah keponakan dari Y
keponakan(X,Y) :- 
    anak(X,U),
    saudara(U,Y).

% suami(X,Y) : X adalah suami dari Y
suami(X,Y) :- 
    pria(X), 
    menikah(X,Y).

% sepupu(X,Y) : X adalah sepupu dari Y
sepupu(X,Y) :- 
    anak(X,U),
    saudara(U,V),
    anak(Y,V).

% menantu(X,Y) : X adalah menantu dari Y
menantu(X,Y) :- 
    anak(X,U),
    menikah(U,Y).

% orangtua(X,Y): X adalah orang tua dari Y
orangtua(X,Y) :- 
    anak(Y,X).

% bibi(X,Y) : X adalah bibi dari Y
bibi(X,Y) :-
    saudara(X,U),
    anak(Y,U),
    wanita(X).
    
% cucu(X,Y) : X adalah cucu dari Y
cucu(X,Y) :- 
    anak(X,U),
    anak(U,Y).

% keturunan(X,Y): X adalah keturunan dari Y (berlaku untuk anak, cucu, dan seterusnya)
keturunan(X,Y) :- anak(X,Y).
keturunan(X,Y) :- cucu(X,Y).
keturunan(X,Y) :- anak(X,U), keturunan(U,Y).
    
% anaksulung(X) : X adalah anak paling tua
% anaksulung(X) :-
%     anak(X,Y),
%     \+ (anak(Z,Y), usia(X,U), usia(Z,V), U<V).
anaksulung(X) :-
    anak(X,Y),
    wanita(Y), /*atau pria(Y)*/
    \+kakak(_,X).

% anakbungsu(X) : X adalah anak paling muda 
% anakbungsu(X) :-
%     anak(X,Y),
%     \+ (anak(Z,Y), usia(X,U), usia(Z,V), U>V).
anakbungsu(X) :-
    anak(X,Y),
    wanita(Y), /*atau pria(Y)*/
    \+kakak(X,_).

/* BAGIAN II: Rekursivitas */
/*
1. combination(N,C,X)
N dalam hal ini adalah total objects, sedangkan C adalah number of objects selected. 
combination(N, C, X) mengeluarkan hasil kombinasi antara N dan C, yaitu X.

*/
combination(0, 0, 1.0).
combination(N, 0, 1.0).
combination(N, N, 1.0).
combination(N, C, X) :-
    N > 0.0,
    N1 is N-1,
    C1 is C-1,
    combination(N1, C1, X1),
    combination(N1, C, X2),
    X is X1 + X2.

/*
2. change(X,Y)
Bayangkan kamu adalah seorang banker. Customer sering datang untuk menukarkan uang mereka. 
Pecahan uang yang kamu punya adalah 1, 2, dan 5. 
Y adalah nilai uang yang customer ingin tukar, sedangkan X adalah jumlah koin atau 
jumlah pecahan uang minimum yang bisa kamu berikan.
*/
change(X, Y) :-
    Y >= 0,
    Y1 is Y - 5,
    change(X1, Y1),
    X is X1 + 1.
change(X, Y) :-
    Y >= 0,
    Y1 is Y - 2,
    change(X1, Y1),
    X is X1 + 1.
change(X, Y) :-
    Y >= 0,
    Y1 is Y - 1,
    change(X1, Y1),
    X is X1 + 1.
change(0, 0).

/*
3. fpb(A,B,X)
X adalah faktor persekutuan terbesar dari A dan B.
*/

fpb(A, B, X) :-
    A = B,
    X is A.
fpb(A, B, X) :-
    A > B,
    A1 is A - B,
    fpb(A1, B, X).
fpb(A, B, X) :-
    A < B,
    B1 is B - A,
    fpb(A, B1, X).

/*
4. mod(A,B,X)
X adalah sisa dari pembagian A terhadap B, 
dengan A >= 0 dan B > 0.
*/

mod(A, B, X) :-
    A >= 0,
    B > 0,
    A < B,
    X is A.

mod(A, B, X) :-
    A >= 0,
    B > 0,
    A >= B,
    A1 is A - B,
    mod(A1, B, X).

/*
5. deret(X,Y)
Diberikan sebuah deret berikut: 1,2,4,5,10,....,dst.
X adalahsuku ke-N dari deret berikut dan Y adalah nilai suku ke-N tersebut.


Contoh:
| ?- deret(6, Y).
Y = 11 ?
yes

? - deret(7, Y).
Y = 22 ?
yes
*/

% deret(1, 1).
% deret(2, 2).
% deret(X, Y) :-

/* BAGIAN III: List */
/*
A. STATISTIK LIST
min : mencari elemen dengan nilai minimum
*/
min([X], X).
min([X|Xs], X) :-
    min(Xs, Y),
    X =< Y.
min([X|Xs], Y) :-
    min(Xs, Y),
    X > Y.

/*
max : mencari elemen dengan nilai maksimum
*/
max([X], X).
max([X|Xs], X) :-
    max(Xs, Y),
    X >= Y.
max([X|Xs], Y) :-
    max(Xs, Y),
    X < Y.

/*
range: mencari selisih antara elemen terbesar dan elemen terkecil
*/
range([X|Xs], Y) :-
    max([X|Xs], Z),
    min([X|Xs], W),
    Y is Z - W.

/*
count : mencari jumlah elemen pada list
*/
count([], 0).
count([_|Xs], Y) :-
    count(Xs, Y1),
    Y is Y1 + 1.

/*
sum : mencari jumlah total elemen pada list
*/
sum([], 0).
sum([X|Xs], Y) :-
    sum(Xs, Y1),
    Y is Y1 + X.

/*
B. List and Queue Manipulation
1. Get Index
Mengembalikan indeks sebuah elemen pada list. 
Jika ada dua elemen yang bernilai sama pada list, 
maka yang dikembalikan adalah yang pertama. 
Jika elemen tidak ditemukan pada list, kembalikan ‘no’. 
Index dimulai dari 1.
*/
getIndex([X|_], X, 1).
getIndex([_|Xs], Y, Z) :-
    getIndex(Xs, Y, Z1),
    Z is Z1 + 1.

/*
2. Swap
Menukar dua buah elemen pada indeks tertentu dan mengembalikan List yang sudah diperbarui nilainya. 
Nilai indeks masukan diasumsikan selalu positif.  
Index dimulai dari 1.

Contoh:
| ?- swap([5,6,7,8], 1, 1, Result).

Result = [5,6,7,8]

yes

| ?- swap([5,6,7,8], 4, 2, Result).

Result = [5,8,7,6]

yes

| ?- swap([5,6,7,8,9], 4, 6, Result).

no

*/
% swap([X|Xs], 1, 1, [X|Xs]).
% swap([X|Xs], 1, Y, [X1|Xs]) :-
%     Y > 1,
%     getIndex(Xs, X1, Y).
% swap([X|Xs], Z, Y, [X1|Xs]) :-

/*
BONUS

Buatlah program kalkulator sederhana dengan mendefinisikan perintah* dan query berikut:
startCalculator: menandakan kalkulator dimulai dan menyimpan nilai 0.
add(X) : menambahkan X ke dalam nilai yang disimpan oleh kalkulator dan menyimpannya
subtract(X): mengurangi X dari nilai yang disimpan oleh kalkulator dan menyimpannya
multiply(X): mengalikan X dengan nilai yang disimpan oleh kalkulator dan menyimpannya
divide(X): membagi nilai yang disimpan oleh kalkulator dengan X dan menyimpannya
clearCalculator: mereset nilai yang disimpan di kalkulator menjadi 0
getValue: mengembalikan nilai yang saat ini disimpan di kalkulator
exitCalculator(X): keluar dari aplikasi kalkulator

Catatan:
Jika permainan belum berlangsung atau sudah selesai, kemudian perintah selain start dimasukkan, kembalikan false (atau no).
Program ini memerlukan fungsi bawaan print dan teknik dynamic predicate. Selamat melakukan eksplorasi. :D
Diperbolehkan menggunakan fungsi I/O untuk merapikan dan memperindah output.
Perhatikan bahwa setiap aksi pada kalkulator, kecuali startCalculator dan getValue, mengeluarkan nilai lama yang disimpan kalkulator dan nilai yang baru.
*/

% startCalculator and initialized value to 0
startCalculator :-
    asserta(savedValue(0)),
    write('Selamat Datang di Kalkulator Prolog!'), nl,
    write('Currently Saved Value is 0'), nl.

% add X to savedValue
add(X) :-
    savedValue(Y),
    Z is Y + X,
    retract(savedValue(Y)),
    asserta(savedValue(Z)),
    write('Old Saved Value is '), write(Y), nl,
    write('New Saved Value is '), write(Z), nl.

% subtract X from savedValue
subtract(X) :-
    savedValue(Y),
    Z is Y - X,
    retract(savedValue(Y)),
    asserta(savedValue(Z)),
    write('Old Saved Value is '), write(Y), nl,
    write('New Saved Value is '), write(Z), nl.

% multiply savedValue with X
multiply(X) :-
    savedValue(Y),
    Z is Y * X,
    retract(savedValue(Y)),
    asserta(savedValue(Z)),
    write('Old Saved Value is '), write(Y), nl,
    write('New Saved Value is '), write(Z), nl.

% divide savedValue with X
divide(X) :-
    savedValue(Y),
    Z is Y / X,
    retract(savedValue(Y)),
    asserta(savedValue(Z)),
    write('Old Saved Value is '), write(Y), nl,
    write('New Saved Value is '), write(Z), nl.

% get savedValue
getValue :-
    savedValue(Y),
    write('Currently Saved Value is '), write(Y), nl.

% clear savedValue
clearCalculator :-
    savedValue(Y),
    retract(savedValue(Y)),
    asserta(savedValue(0)),
    write('Old Saved Value is '), write(Y), nl,
    write('New Saved Value is 0'), nl.

% exit calculator
exitCalculator :-
    write('Terima Kasih telah Menggunakan Kalkulator Prolog'), nl,
    retractall(savedValue(_)).