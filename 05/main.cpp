#include "BigInt.h"

int main() {
	BigInt a("10999999999999999999999999");
	BigInt b("30001023123421345423542353");
	BigInt c = -b;
	BigInt t(-1);
	BigInt zero(0);
	std::cout << "Starting tests:";
	std:: cout << "\nshould be 0, got " << zero;
	std::cout << "\nshould be 0, got " << b + c;
	std::cout << "\nshould be -19001023123421345423542354, got " << a - b;
	c = 500;
	t = -400;
	BigInt p(500);
	std::cout << "\nshould be 100, got " << t + c;
	bool var1 = c >= t;
	bool var2 = t != c;
	bool var3 = c == p;
	bool var4 = t <= c;
	bool var5 = t < c;
	bool var6 = c > t;
	std::cout << "\nshould be 111111, got " << var1 << var2 << var3 << var4 << var5 << var6 << "\n";
	std::cout << "Tests are over, check if all is correct\n";
	return 0;
}
