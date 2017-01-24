all: lab5

lab5: lab5.o 
	g++ lab5.o -o lab5

lab5.o: lab5.cpp
	g++ -c lab5.cpp -o lab5.o

run: all
	./lab5

clean:
	rm -f *.o lab5
