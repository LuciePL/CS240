all: submission

submission: submission.o
	g++ -std=c++11 -g submission.o -o submission

submission.o: submission.cpp
	g++ -c -std=c++11 -g submission.cpp -o submission.o

run: all
	./submission

clean:
	rm -f *.o submission
