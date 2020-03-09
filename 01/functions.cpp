#include <cstdlib>
#include "assigning.h"


char*right;
char* start;
size_t num_bites;

void makeAllocator(size_t max_Size) {
	start = (char*) std::malloc(max_Size);
	right = start;
	num_bites = max_Size;
}

char* alloc(size_t size) {
	if (right + size > start + num_bites - 1) {
		return nullptr;
	}
	right += size;
	char* tmp = right - size_t(size);
	return tmp;
}

void reset(void) {
	right = start;
}

