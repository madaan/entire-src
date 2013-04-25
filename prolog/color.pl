% coloring1(+Graph,+Colors,-Coloring)
coloring1(g(Vs,Es),Colors,Coloring):-
   gener(Vs,Colors,Coloring),
   test(Es,Coloring).
   
% gener(+Vertices,+Colors,-Coloring)
gener([],_,[]).
gener([V|Vs],Colors,[V-C|T]):-
   member(C,Colors), % non-deterministic generator of colors
   gener(Vs,Colors,T).
   
% test(+Edges,+Coloring)
test([],_).
test([e(V1,V2)|Es],Coloring):-
   member(V1-C1,Coloring), % find color of vertex V1
   member(V2-C2,Coloring), % find color of vertex V2
   C1\=C2,                 % test the difference of colors
   test(Es,Coloring).
