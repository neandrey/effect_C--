// ex7.3
// Изменить код так, чтобы при обнаружении нескольких вхождений одного и того же
// номера строки программа выводила этот номер только 1 раз.

// Решение - заменяем тип vector на тип set в map<string set<int>>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include "xref.h"
//#include "split.h"

using std::string;  using std::set;
using std::map;     using std::cout;
using std::cin;     using std::endl; 

string find_line(const set<int>&);

int main() {

    map<string, set<int>> ret = xref(cin);

    for (auto it : ret)
        cout << it.first << " встречается на строке (строках): " << find_line(it.second) << endl;
    cout << endl;

    return 0;
}

string find_line(const set<int>& v)
{
    string res;
    for (auto it : v)
        res += std::to_string(it) + ' ';

    return res;
}
