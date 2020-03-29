CC=g++ -std=c++14
  
all: test

parse: main.cpp functions.cpp declaring.h
	$(CC) -o parse main.cpp functions.cpp  
 
test: parse  
	./parse
