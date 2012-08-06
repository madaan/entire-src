#sg
temll: build/LinkedList.o build/tester.o 
	g++ -o temll  build/tester.o build/LinkedList.o
build/LinkedList.o : LinkedList.cpp LinkedList.h 
	g++ -c LinkedList.cpp
	mv *.o build
build/tester.o : tester.cpp
	g++ -c tester.cpp
	mv *.o build
clean: 
	rm build/*.o
	
