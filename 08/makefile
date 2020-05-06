CC=g++ -std=c++14
  
all: run

test: test.cpp ThreadPool.h
	$(CC) -o test test.cpp -lpthread 
 
run: test  
	./test
