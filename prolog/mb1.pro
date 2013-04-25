/*Monkey first gets the chair and then he gets the stick*/
/*Finally he jumps on the chair and gets the banana bunch with a stick*/

/*mb(POSITION, CHAIR?, STICK?, ONCHAIR?)*/
mb(center, haschair, hasstick, onchair):-
    write('Hitting the banana bunch with a stick'),nl.

/*Climb up if you have everything*/
mb(center, haschair, hasstick, onground):-
    write('Climbing up'),nl,mb(center, haschair, hasstick, onchair).

/*goto the chair*/
mb(center, nochair, S, onground):-
    move(mb(center, nochair, S, onground), chairlocation).

/*pick the chair and move back*/    
mb(chairlocation, nochair, S, onground):-
    write('Getting the chair'), nl,mb(chairlocation, haschair, S, onground).

mb(chairlocation, haschair, S, onground):-
    move(mb(chairlocation, haschair, S, onground), center).

/*goto stick location*/
mb(center, C, nostick, onground):-
    move(mb(center , C, nostick, onground), sticklocation).

/*pick the stick and move back*/    
mb(sticklocation, C, nostick, onground):-
    write('Getting the stick'), nl, 
    move(mb(sticklocation, C, hasstick, onground), center).
mb(sticklocation, C, hasstick, onground):-
    move(mb(sticklocation, C, hasstick, onground), center).

/*Move from P to Y*/
move(mb(P, C, S, G), Y):- 
    write('Moving from '), write(P), write(' to '), write(Y), nl,mb(Y, C, S, G).

   
