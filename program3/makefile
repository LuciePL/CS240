all: program3

program3: program3.o Map.o City.o
	g++ -std=c++11 program3.o Map.o City.o -o program3

program3.o: program3.cpp
	g++ -c -std=c++11 -g program3.cpp -o program3.o

Map.o: Map.cpp Map.h
	g++ -c -std=c++11 -g Map.cpp -o Map.o

City.o: City.cpp City.h
	g++ -c -std=c++11 -g City.cpp -o City.o

run: all
	./program3

clean:
	rm -f *.o program3
