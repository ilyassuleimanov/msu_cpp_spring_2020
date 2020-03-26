#include "declaring.h"

int main() {
	Matrix m(3, 3);
	Matrix m1(3,3);
	Matrix m2(3,3);
	Matrix m3(3,3);
	for (size_t i = 0; i != 3; ++i) {
		for (size_t j = 0; j != 3; ++j) {
			m[i][j] = 1;
			m1[i][j] = 1;
			m2[i][j] = 0;
			m3[i][j] = 5;
		}
	}
	std::cout << "Starting tests:\n";
	assert(m != m2);
	std::cout << "Test 1 passed\n";
	assert(m == m1);
	std::cout << "Test 2 passed\n";
	m *= 5;
	assert(m == m3);
	std::cout << "Test 3 passed\n";
	assert((m.getRows() == 3) && (m.getCols() == 3));
	std::cout << "Test 4 passed\n";
	std::cout << "All tests successfully passed\n";

	return 0;
}
