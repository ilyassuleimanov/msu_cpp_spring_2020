#include "matrix.h"

Matrix::~Matrix() {
	if (arr != nullptr) {
		for (size_t i = 0; i != rows; ++i) {
			delete[] arr[i];
		}
	}
	delete[] arr;
}

Matrix::Proxy::Proxy(int* ii, size_t jj) {
	i = ii;
	j = jj;
}

int& Matrix::Proxy::operator[] (size_t jj) {
	if (jj > j) {
		throw std::out_of_range("");
	}
	return i[jj];
}

Matrix::Proxy Matrix::operator[] (size_t i) {
	if (i > rows) {
		throw std::out_of_range("");
	}
	return Matrix::Proxy(arr[i], cols);
}

Matrix::Matrix(size_t r, size_t c) {
	rows = r;
	cols = c;
	arr = new int*[rows];
	for (size_t i =0; i !=cols; ++i) {
		arr[i] = new int[cols];
	}
}

size_t Matrix::getRows() {
	return rows;
}

size_t Matrix::getCols() {
	return cols;
}

Matrix& Matrix::operator*= (int k) {
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			arr[i][j] *= k;
		}
	}
	return *this;
}

bool Matrix::operator== (const Matrix& m) {
	if ((rows != m.rows) || (cols != m.cols)) return false;
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			if (arr[i][j] != m.arr[i][j]) return false;
		}
	}
	return true;
}

bool Matrix::operator!= (const Matrix& m) {
	return !(*this == m);
}
