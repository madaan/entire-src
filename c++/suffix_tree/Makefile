stree : build/suffix_tree.o build/driver.o
	g++ -o stree build/suffix_tree.o build/driver.o

build/suffix_tree.o : suffix_tree.h suffix_tree.cpp
	g++ -c suffix_tree.cpp -o build/suffix_tree.o

build/driver.o : driver.cpp
	g++ -c driver.cpp -o build/driver.o

clean : 
	rm build/*.o
