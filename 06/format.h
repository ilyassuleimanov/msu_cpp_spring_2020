#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <cassert>
#pragma once

void to_vec(std::vector<std::string>& vec) {
	return;
}

template <class T>
void to_vec(std::vector<std::string>& vec, const T& val) {
	std::stringstream ss;
	ss << val;
	std::string s;
	ss >> s;
	vec.push_back(s);
}

template <class T, class ...Args>
void to_vec(std::vector<std::string>& vec, const T& val, const Args& ...args) {
	std::stringstream ss;
	ss << val;
	std::string s;
	ss >> s;
	vec.push_back(s);
	to_vec(vec, args...);
}

int c2i(char x) {
	return x - '0';
}

template <class ...Args>
std::string format(const std::string& str, const Args& ...args) {
	std::vector<std::string> vec;
	std::string res = "";
	to_vec(vec, args...);
	int num_params = vec.size();
	size_t len = str.size();
	int subst = -1;
	int brackets_counter = -1;
	bool flag = false;
	for (size_t i = 0; i != len; ++i) {
		if (flag == true) {
			if (str[i] == '}') {
				if (subst != -1) {
					if (subst >= num_params)
						throw std::runtime_error ("Number in brackets is too large");
					res += vec[subst];
					subst = -1;
				}
				else {
					res += vec[brackets_counter];
				}
				flag = false;
				continue;
			}
			if (i == len - 1) {
				throw std::runtime_error ("Closing bracket was not met after opening one");
			}
			else {
				if (subst == -1) {
					subst = c2i(str[i]);
				}
				else {
					subst = subst * 10 + c2i(str[i]);
				}
				continue;
			}
		}
		if (str[i] == '{') {
			++brackets_counter;
			flag = true;
			continue;
		}
		if (str[i] == '}') {
			throw std::runtime_error ("Met closing bracket before opening one");
		}
		res += str[i];
	}
	return res;
}

