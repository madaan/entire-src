/*sg*/
gc(g(Vs,Es),CL,COLORING):-
    color(Vs,CL,COLORING),
    test(Es,COLORING).
color([],_,[]).
color([V|VT], CL, [V-C|T]):-
    member(C,CL),color(VT,CL,T).
test([],_).
test([V1-V2|T],COLORING):-
    member(V1-X,COLORING),
    member(V2-Y,COLORING),
    X\=Y,
    test(T,COLORING).
