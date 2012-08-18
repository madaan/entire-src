#sg

llexec: build/LinkedList.o build/LinkedListTester.o ../NodeDef/build/Node.o
	g++ -o llexec build/LinkedList.o build/LinkedListTester.o ~/DS/NodeDef/build/Node.o
build/LinkedList.o: LinkedList.cc LinkedList.h ../NodeDef/Node.h ../NodeDef/Node.cc
	g++ -c LinkedList.cc 
	mv *.o build
build/LinkedListTester.o: LinkedListTester.cc
	g++ -c LinkedListTester.cc 
	mv *.o build
../NodeDef/build/Node.o : ~/DS/NodeDef/Node.cc
	g++ -c ~/DS/NodeDef/Node.cc
	mv *.o ~/DS/NodeDef/build
clean:
	#clean build
	rm build/*.o
