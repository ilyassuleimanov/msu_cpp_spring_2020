CC=g++ -std=c++14
  
all: test

test: main.cpp functions.cpp declaring.h
	$(CC) -o test main.cpp functions.cpp  
 
run: test  
	./test
