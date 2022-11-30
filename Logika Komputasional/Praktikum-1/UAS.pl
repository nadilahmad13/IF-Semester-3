% Fungsi isMember, menerima dua buah term yaitu variabel dan list, 
% dan mengembalikan nilai boolean yang menunjukkan apakah variabel tersebut merupakan anggota dari list.

isMember(X, [X|_]).
isMember(X, [_|T]) :- 
    isMember(X, T).