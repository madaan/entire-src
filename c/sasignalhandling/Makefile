gterm : build/GracefulTerminator.o build/handlers.o
	gcc -o gterm build/GracefulTerminator.o build/handlers.o

build/handlers.o : handlers.c handlers.h
	gcc -c handlers.c && mv *.o build

build/GracefulTerminator.o : GracefulTerminator.c
	gcc -c GracefulTerminator.c -Wno-div-by-zero && mv *.o build 





