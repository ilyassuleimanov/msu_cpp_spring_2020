#include <iostream>
#include "assigning.h"


int main() {
	try {
		makeAllocator(1024);
	}
	catch(const char* str) {
		std::cout << str << "\n";
	}
	std::cout << "starting test:\n";
	char* p1 = alloc(200);
	char* p2 = alloc(500);
	char* p3 = alloc(500);
	if ((p1) && (p2) && !(p3)) {
		std::cout << "correct\n";
	}
	else {
		std::cout << "mistake\n";
	}
	return 0;
}

