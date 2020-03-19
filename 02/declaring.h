#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#pragma once

using on_number = void (*) (int num, std::vector<std::string>& vec);
using on_str = void (*) (const std::string& str, std::vector<std::string>& vec);
using on_start_or_stop = void (*) (void);

void register_on_num (on_number callback);
void register_on_str (on_str callback);
void register_on_start(on_start_or_stop callback);
void register_on_stop(on_start_or_stop callback);
void parse(const std::string& text, std::vector<std::string>& vec);
