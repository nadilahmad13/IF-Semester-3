grade(N,a) :- N >= 70, !.
grade(N,b) :- N < 70, N >= 63, !.
grade(N,c) :- N < 63, N >= 55, !.
grade(N,d) :- N < 55, N >= 50, !.
grade(N,e) :- N < 50, N >= 40, !.
grade(N,f) :- N < 40.