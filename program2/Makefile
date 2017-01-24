all: program2

program2: program2.o Heap.o Player.o Table.o
	g++ -std=c++11 -g program2.o Heap.o Player.o Table.o -o program2

program2.o: program2.cpp
	g++ -c -std=c++11 -g program2.cpp -o program2.o

Heap.o: Heap.cpp Heap.h
	g++ -c -std=c++11 -g Heap.cpp -o Heap.o
	
Player.o: Player.cpp Player.h
	g++ -c -std=c++11 -g Player.cpp -o Player.o

Table.o: Table.cpp Table.h
	g++ -c -std=c++11 -g Table.cpp -o Table.o
	
run: all
	./program2

clean:
	rm -f *.o program2
