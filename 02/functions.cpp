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

void parse(const std::string& text) {
	if (!(start_callback && stop_callback && num_callback && str_callback)) return;
	start_callback();	
	size_t curr_pos = 0;
	while (curr_pos < text.length()) {
		size_t offset = 0;
		while (std::isspace(text[curr_pos])) ++curr_pos;
		if (std::isdigit(text[curr_pos])) {
			while (std::isdigit(text[curr_pos + offset])) {
				++offset;
			}
			auto tmp = std::stoi(text.substr(curr_pos, offset));
			num_callback(tmp);
			curr_pos += offset;
		}
		else {
			while ((!std::isdigit(text[curr_pos + offset])) && (!std::isspace(text[curr_pos + offset]))) {
				++offset;
			}
			str_callback(text.substr(curr_pos, offset));
			curr_pos += offset;
		}
	}
	stop_callback();
}
