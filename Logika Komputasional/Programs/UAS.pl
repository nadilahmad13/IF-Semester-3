% Fungsi isMember, menerima dua buah term yaitu variabel dan list, 
% dan mengembalikan nilai boolean yang menunjukkan apakah variabel tersebut merupakan anggota dari list.

isMember(X, [X|_]) :- !.
isMember(X, [_|T]) :- 
    isMember(X, T).

/*
predikat intersectList yang menerima dua buah list (L1 dan L2) dan menghasilkan
satu buah list (L3) yang berisi nilai yang beririsan antara L1 dan L2. Jadi predikat
intersectList memiliki 3 term yaitu dua term berupa dua buah list masukan dan sebuah term
sebagai list hasil. Predikat intersectList harus memanfaatkan predikat isMember.
*/

intersectList([], _, []) :- !. % Basis

intersectList([H|T], L2, [H|T3]) :- % Rekurens, jika Head L1 merupakan anggota L2
    isMember(H, L2), !,
    intersectList(T, L2, T3).

intersectList([_|T], L2, T3) :- % Rekurens, jika Head L1 bukan merupakan anggota L2
    intersectList(T, L2, T3).

% contoh query
% ?- intersectList([1,2,3,4,5], [3,4,5,6,7], L).

% classify
classify(0,zero).
classify(N,negative):-N < 0.
classify(N,positive):-N > 0.
go :- 
    write(start),nl,
    repeat,write('enter a positive value'),nl,read(N),
    classify(N,Type),Type=positive,
    write('positive value is '),write(N),nl.