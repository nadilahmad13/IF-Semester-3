faktorial(0,1) :- !.
faktorial(X,Y) :- X1 is X-1, faktorial(X1,Y1), Y is X*Y1.