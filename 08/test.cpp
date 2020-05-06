#include "ThreadPool.h"

int f1(int a) {
	std::cout << "Test number 1\n";
    return a * 10;
}

int f2(int a, int b, int c) {
	std::cout << "Test number 2\n";
    return (a + b - c) * 10;
}

int f3(std::string str){
	std::cout << "Test number 3\n";
    return str.length();
}

int main(){
    std::cout << "Starting tests\n";
    ThreadPool pool(3);
    auto task1 = pool.exec(f1, 22);
    int test1 = task1.get();
    assert(test1 == 220);
    auto task2 = pool.exec(f2, 10, 15, 5);
    int test2 = task2.get();
    assert(test2 == 200);
    auto task3 =pool.exec(f3, "the last test");
    int test3 = task3.get();
    assert(test3 == 13);
    std::cout << "All tests passed\n";
}
