/*sg*/
center(1,1).

move(X,Y,C):-
    member(X,C),
    member(Y,C),
    moveStick(X,Y).

moveStick(X,Y):-
    X<2,
    Y<2,
    center(X,Y);
    X<1,Y<2,inc(X,X1),moveStick(X1,Y),write('moving to : '),write(X1),write(','),write(Y),nl;
    X<2,Y<1,inc(Y,Y1),moveStick(X,Y1),write('moving to : '),write(X),write(','),write(Y1),nl.

inc(X,X1):-
    X1 is X + 1.
