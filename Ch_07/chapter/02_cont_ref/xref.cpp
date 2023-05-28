#include "xref.h"

using std::vector;  using std::string;
using std::map;     using std::istream; 
using std::getline;

map<string, vector<int>> xref(istream &in, vector<string> find_words(const string&))
{
    string line;
    int line_number = 0;
    map<string, vector<int>> ret;

    while (getline(in, line)) {
        ++line_number;

        vector<string> words = find_words(line);

        for (auto it : words)
            ret[it].push_back(line_number);
    }

    return ret;
}
