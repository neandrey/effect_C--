#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);
bool bracketed(const std::string&);
void gen_aux(const Grammar& g, const std::string& word, 
             std::vector<std::string>&);
int nrand(int);