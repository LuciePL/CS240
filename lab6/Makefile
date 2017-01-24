all: lab6

lab6: lab6.o BSTree.o
	g++ lab6.o BSTree.o -o lab6

lab6.o: lab6.cpp
	g++ -c lab6.cpp -o lab6.o

BSTree.o: BSTree.cpp BSTree.h
	g++ -c BSTree.cpp -o BSTree.o

run: all
	./lab6

clean:
	rm -f *.o lab6
