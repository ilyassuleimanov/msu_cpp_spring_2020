#include "format.h"

int main() {
	std::string string = format("abcd {} {}.", 1,"abcd", 1);
    assert(string == "abcd 1 abcd.");
    std::cout << "\nTest 1 passed";
    
    string = format("");
    assert(string == "");
    std::cout << "\nTest 2 passed";
    
    string = format("abcd {3} {1}.", 1, "abcd", 1, 4);
    assert(string == "abcd 4 abcd.");
    std::cout << "\nTest 3 passed.";
    std::cout << "\nAll tests successfully passed\n";
	return 0;
}
