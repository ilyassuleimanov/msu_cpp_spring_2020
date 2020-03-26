#include <iostream>
#include <stdexcept>
#include <cassert>

class Matrix {
	size_t rows = 0;
	size_t cols = 0;
	int** arr = nullptr;
	public:
		class Proxy {
			public:
			size_t j = 0;
			int* i = nullptr;
			Proxy(int* ii, size_t jj);
			int& operator[] (size_t j);

		};
		Matrix(size_t r, size_t c);
		size_t getRows();
		size_t getCols();
		Matrix& operator*= (int k);
		bool operator== (Matrix& m);
		bool operator!= (Matrix& m);
		Proxy operator[] (size_t i);
		~Matrix();
};

