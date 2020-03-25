#include "declaring.h"

int num_letters = 0;
int num_numbers = 0;

void Start_callback(void) {
	std::cout << "Started parsing\n";
}

void Stop_callback(void) {
	std::cout << "Stopped parsing\n";
}

void Str_callback(const std::string& str) {
	std::cout << str << "\n";
	num_letters += 1;
}

void Num_callback(int num) {
	std::cout << num << "\n";
	num_numbers += 1;
}

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

	if (num_letters != 4) {
		std::cout << "error";
		return 1;
	}
	if (num_numbers != 3) {
		std::cout << "error";
		return 1;
	}

std::cout << "all tests passed\n";

	return 0;
}
