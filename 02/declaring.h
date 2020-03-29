#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <functional>
#include <cassert>
#pragma once

using on_start_or_stop = void (*) (void);
using on_number = std::function<void(int)>;
using on_str = std::function<void(const std::string&)>;

void register_on_num (on_number callback);
void register_on_str (on_str callback);
void register_on_start(on_start_or_stop callback);
void register_on_stop(on_start_or_stop callback);
void parse(const std::string& text);
