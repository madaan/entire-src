/*sg*/
rice(brown):-
    color(brown).
 
rice(carolina):-
    length(large),
    color(white),
    stickiness(present).

rice(arborio):-
    length(medium),
    aroma(mild),
    color(creamy).

rice(basmati):-
    length(large),
    aroma(strong),
    color(white),
    flavor(nutty),
    stickiness(absent).

rice(black):-
    length(medium),
    aroma(medium),
    color(black),
    flavor(mild_nutty),
    stickiness(present).
    
rice(kalijira):-
    length(small),
    aroma(strong),
    color(white),
    flavor(nutty),
    stickiness(absent).
    
rice(china_black):-
    length(small),
    aroma(strong),
    color(black),
    flavor(nutty),
    stickiness(absent).
    
rice(unknown):-
    write('Sorry, I cannot say much about the variety you have. Perhaps you have discovered a new variety!').
length(X):-ask(length, X).

aroma(X):-ask(aroma, X).

color(X):- ask(color, X).

flavor(X):- ask(flavor, X).

stickiness(X):- ask(stickiness, X).
/* Simpler Alternative : 
ask(A,B):-
    write(A:B),
    write('? '),
    nl,
    read(yes).
*/
ask(A, V):-
    known(y, A, V), % succeed if true
    !. % stop looking

ask(A, V):-
    known(_, A, V), % fail if false
    !, fail.

ask(A, V):-
    write('Is '),
    write(A),
    write(' '),
    write(V), % ask user
    write('?  (y/n)->'),
    read(Y), % get the answer
    asserta(known(Y, A, V)), % remember it
    Y == y. % succeed or fail

:-dynamic(known/3).

go:-
    write('Welcome!'),nl,nl,
    write('I will help you in identifying the species of rice you are not sure about'),nl,nl,
    write('Just answer a few questions to help me'),nl,nl,
    rice(X),nl,
    write('The species is '),write(X),write('.'),nl,write('Hope this helped, see you again!').
