#sg

sdes: build/SDES.o build/CharDataConverter.o
	g++ -o sdes build/SDES.o build/CharDataConverter.o
    
build/SDES.o: SDES.cpp SDES.h
	g++ -c SDES.cpp
	mv *.o build

build/CharDataConverter.o: CharDataConverter.cpp CharDataConverter.h
	g++ -c CharDataConverter.cpp
	mv *.o build
    
clean:
	rm build/*.o  
