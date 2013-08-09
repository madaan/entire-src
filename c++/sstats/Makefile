stats : simple.o plot.o stats.o
	g++ build/*.o -o stats

simple.o : simple.h simple.cpp
	g++ -c simple.cpp && mv *.o build

plot.o : plot.cpp plot.h
	g++ -c plot.cpp && mv *.o build

stats.o : stats.cpp
	g++ -c stats.cpp && mv *.o build


	
