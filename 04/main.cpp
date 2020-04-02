#include "ser-des.h"

struct Data {
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer) {
        return serializer(a, b, c);
    }
};

int main() {
	
	Data x { 10, true, 2 };
	
	std::stringstream stream;
	
	Serializer serializer(stream);
	serializer.save(x);
		
	Data y { 0, false, 0 };
	
	Deserializer deserializer(stream);
	const Error err = deserializer.load(y);
	
	std::cout << "Starting tests:\n";
	assert(err == Error::NoError);
	std::cout << "test 1 passed\n";
	assert(x.a == y.a);
	std::cout << "test 2 passed\n";
	assert(x.b == y.b);
	std::cout << "test 3 passed\n";
	assert(x.c == y.c);
	std::cout << "test 4 passed\n";
	std::cout << "All tests passed";
	
	return 0;
}
