all: lab3


lab3: lab3.o MovieChart.o
	g++ -g lab3.o MovieChart.o -o lab3

lab3.o: lab3.cpp
	g++ -g -c lab3.cpp -o lab3.o

MovieChart.o: MovieChart.h MovieChart.cpp
	g++ -g -c MovieChart.cpp -o MovieChart.o

run: all
	./lab3

clean:
	rm -f *.o lab3
