#include "declaring.h"

void Start_callback(void) {
	std::cout << "Started parsing\n";
}

void Stop_callback(void) {
	std::cout << "Stopped parsing\n";
}

std::vector<std::string> vec;

on_number Num_callback = [=] (int num) {
	vec.push_back(std::to_string(num));
	std::cout << num << "\n";
};

on_str Str_callback = [=] (const std::string& str) {
	vec.push_back(str);
	std::cout << str << "\n";
};

int main() {
	register_on_num(Num_callback);
	register_on_str(Str_callback);
	register_on_start(Start_callback);
	register_on_stop(Stop_callback);
	
	if (!(Start_callback && Stop_callback && Num_callback && Str_callback)) {
		std::cout << "error";
		return 1;
	}
		
	std::string s("   jd  yh292222nxm    \t7fh\n  \t\t  55");
	parse(s);
	std::vector<std::string> vec1 = {"jd", "yh", "292222", "nxm", "7", "fh", "55"};
	for (int i = 0; i != 7; ++i) {
		assert(vec[i] == vec1[i]);
	}
	
	std::cout << "all tests passed\n";

	return 0;
}
