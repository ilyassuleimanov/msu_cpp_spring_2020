CC=g++ -std=c++14
  
all: test

test: main.cpp matrix.cpp matrix.h
	$(CC) -o test main.cpp matrix.cpp  
 
run: test  
	./test
