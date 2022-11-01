/* FAKTA */

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
saudara(wesly, wulandari).
saudara(wulandari, wesly).

/* ATURAN */
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
keturunan(X,Y) :-
    anak(X,Z),
    keturunan(Z,Y).
    
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

adik(X,Y) :-
    saudara(X,Y),
    usia(X,U),
    usia(Y,V),
    U<V.

% QUERY
% a. Istri dari Vito
% ?- menikah(X,vito).

% b. Adik dari Elon Musk
% ?- saudara(X,elonMusk).

% c. Cicit dari Gojo
% ?- anak(X,gojo), anak(Y,X), anak(Z,Y).

% Paman atau bibi tertua dari Wesly (pilih yang tertua)
% ?- anak(X,wesly),