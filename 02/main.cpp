#include "declaring.h"

void Start_callback(void) {
	std::cout << "Started parsing\n";
}

void Stop_callback(void) {
	std::cout << "Stopped parsing\n";
}

void Str_callback(const std::string& str) {
	std::cout << str << "\n";
}

void Num_callback(const std::string& num) {
	std::cout << num << "\n";
}



int main() {
	register_on_num(Num_callback);
	register_on_str(Str_callback);
	register_on_start(Start_callback);
	register_on_stop(Stop_callback);
	if (!(start_callback && stop_callback && num_callback && str_callback)) {
		std::cout << "error";
		return 1;
	}
	
	std::string s("   jd      \t7fh\n  \t\t  55");
	std::vector<std::string> vec1;
	std::vector<std::string> vec = {"jd", "7", "fh", "55"};
	parse(s, vec1);
	if (vec == vec1) {
		std::cout << "test1 passed\n";
	}
	else {
		std::cout << "wrong answer";
		return 1;
	}
	
	s = "\t\tsdf56h\n\n\n77f";
	vec1.clear();
	vec = {"sdf", "56", "h", "77", "f"};
	parse(s, vec1);
	if (vec == vec1) {
		std::cout << "test2 passed\n";
	}
	else {
		std::cout << "wrong answer";
		return 1;
	}
	return 0;
}
