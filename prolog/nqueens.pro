
solution([]).
solution([X/Y|Others]) :-
 solution(Others),
 memberC(Y, [1,2,3,4]),
 noattack(X/Y, Others).
 
noattack(_,[]).
 
noattack(X/Y,[X1/Y1|Others]) :-
 Y =\= Y1,
 Y1 - Y =\= X1 - X,
 Y1 - Y =\= X - X1,
 noattack(X/Y,Others).
 
memberC(Item,[Item|Rest]).
 
memberC(Item,[First|Rest]) :-
 memberC(Item,Rest).
 
template([1/Y1,2/Y2,3/Y3,4/Y4,5/Y5,6/Y6,7/Y7,8/Y8]).
