#include <iostream>
#include <string>
#include <vector>
#pragma once

using on_number = void (*) (const std::string& num);
using on_str = void (*) (const std::string& str);
using on_start_or_stop = void (*) (void);

extern on_number num_callback;
extern on_str str_callback;
extern on_start_or_stop start_callback;
extern on_start_or_stop stop_callback;

void register_on_num (on_number callback);
void register_on_str (on_str callback);
void register_on_start(on_start_or_stop callback);
void register_on_stop(on_start_or_stop callback);
bool is_sep (const char& s);
void parse(const std::string& text, std::vector<std::string>& vec);
