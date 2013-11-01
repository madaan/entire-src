cl : count-lines.l
	lex count-lines.l
	gcc -c *.c
	gcc -o cl *.o -ll

clwc : count-lwc.l
	lex count-lwc.l
	gcc -c *.c
	gcc -o clwc *.o -ll

cdec : count-num.l
	lex count-num.l
	gcc -c *.c
	gcc -o cdec *.o -ll

calc : calc.l calc.y
	yacc -d calc.y
	lex calc.l
	gcc -c *.c
	gcc -o calc *.o -ll

tcln : text-cleanup.l
	lex text-cleanup.l
	gcc -c *.c
	gcc -o tcln *.o -ll


ex1 : ex1.l ex1.y
	yacc -d ex1.y
	lex ex1.l
	gcc -c *.c
	gcc -o ex1 *.o -ll


clean :
	-rm *.c *.o *.h
	-rm cl
	-rm calc cdec cl clwc


