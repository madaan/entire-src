sound(time1).
sound(time2).
sun(time3).
relax(X):-sound(X),un(X).
relax(_):-sun(_).
