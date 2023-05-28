#ifndef SPLIT_H
#define SPLIT_H
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cctype>

bool space(char c);
bool not_space(char c);
std::vector<std::string> split(const std::string&);


#endif