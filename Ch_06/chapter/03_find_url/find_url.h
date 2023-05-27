#ifndef FIND_URL_H
#define FIND_URL_H
#include <vector>
#include <string>
#include <iterator>

std::vector<std::string> find_urls(const std::string& s);
std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e);
bool not_url_char(char c);
std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e);

#endif