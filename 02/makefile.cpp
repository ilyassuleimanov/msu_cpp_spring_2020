CC=g++

all: test

main.o: main.cpp declaring.h
	$(CC) -c main.cpp

Callback.o: functions.cpp declaring.h
	$(CC) -c functions.cpp

Call: main.o functions.o
	$(CC) -o Call main.o functions.o

test: Call
	./Call

clean:
	rm -rf *.o test
	rm -rf *.o Call
