CC=g++ -std=c++14
  
all: parse

parse: main.cpp functions.cpp declaring.h
	$(CC) -o parse main.cpp functions.cpp  
 
test: parse  
	./parse
