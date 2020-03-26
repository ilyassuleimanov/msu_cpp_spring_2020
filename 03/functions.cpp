#include "declaring.h"

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
	if ((jj < 0) || (jj > j)) {
		throw std::out_of_range("");
	}
	return i[jj];
}

Matrix::Proxy Matrix::operator[] (size_t i) {
	if ((i < 0) || (i > rows)) {
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
	if (arr == nullptr) {
		throw std::out_of_range("");
	}
	for (size_t i = 0; i != rows; ++i) {
		if (arr[i] == nullptr) {
			throw std::out_of_range("");
		}
		for (size_t j = 0; j != cols; ++j) {
			arr[i][j] *= k;
		}
	}
	return *this;
}

bool Matrix::operator== (Matrix& m) {
	if ((rows != m.getRows()) || (cols != m.getCols())) return false;
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			if (arr[i][j] != m[i][j]) return false;
		}
	}
	return true;
}

bool Matrix::operator!= (Matrix& m) {
	return !(*this == m);
}
