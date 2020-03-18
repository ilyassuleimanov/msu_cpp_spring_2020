#include "declaring.h"

on_number num_callback;
on_str str_callback;
on_start_or_stop start_callback;
on_start_or_stop stop_callback;

void register_on_num (on_number callback) {
	num_callback = callback;
}

void register_on_str (on_str callback) {
	str_callback = callback;
}

void register_on_start(on_start_or_stop callback) {
	start_callback = callback;
}

void register_on_stop(on_start_or_stop callback) {
	stop_callback = callback;
}

bool is_sep (const char& s) {
	return ((s == ' ') || (s == '\n') || (s == '\t'));
}

void parse(const std::string& text, std::vector<std::string>& vec) {
	if (!(start_callback && stop_callback && num_callback && str_callback)) return;
	start_callback();	
	int curr_pos = 0;
	while (curr_pos < text.length()) {
		int offset = 0;
		while (is_sep(text[curr_pos])) ++curr_pos;
		if (std::isdigit(text[curr_pos])) {
			while (std::isdigit(text[curr_pos + offset])) {
				++offset;
			}
			num_callback(text.substr(curr_pos, offset));
			vec.push_back(text.substr(curr_pos, offset));
			curr_pos += offset;
		}
		else {
			while ((!std::isdigit(text[curr_pos + offset])) && (!is_sep(text[curr_pos + offset]))) {
				++offset;
			}
			str_callback(text.substr(curr_pos, offset));
			vec.push_back(text.substr(curr_pos, offset));
			curr_pos += offset;
		}
	}
	stop_callback();
}
