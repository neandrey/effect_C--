// Подсчeт ссылок в строке.
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "xref.h"
//#include "split.h"

using std::string;  using std::vector;
using std::map;     using std::cout;
using std::cin;     using std::endl; 

string find_line(const vector<int>&);

int main() {

    map<string, vector<int>> ret = xref(cin);

    for (auto it : ret)
        cout << it.first << " встречается на строке (строках): " << find_line(it.second) << endl;
    cout << endl;

    return 0;
}

string find_line(const vector<int>& v)
{
    string res;
    for (auto it : v)
        res += std::to_string(it) + ' ';

    return res;
}
