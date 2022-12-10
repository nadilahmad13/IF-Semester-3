% write to a file

writeFile :- 
    open('test.txt', write, Stream),
    write(Stream, 'Hello World'), 
    close(Stream).

writeInput:-
    open('test.txt', read, S),
    read(S,H1),
    read(S,H2),
    read(S,H3),
    read(S,H4),
    close(S),
    write([H1,H2,H3,H4]),nl.