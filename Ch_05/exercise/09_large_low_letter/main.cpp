// Напишите программу для вывода слов (из введенных даннх)
// строчными буквами, а после них - прописными буквами.
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "split.h"
#include "lower_upper.h"


using std::string;  using std::vector;
using std::getline; using std::cin;
using std::cout;    using std::endl;
using std::tolower; using std::toupper;


int main() {

    vector<string> v_str;
    // Ввод строк из потока.
    for (string s; getline(cin, s); )
    {
        v_str = split(s);
    }

    // вывод строчных букв.
    for (auto s : v_str)
        cout << to_lower(s) << ' ';
    cout << endl;

    // вывод пропесных букв.
    for (auto s : v_str)
        cout << to_upper(s) << ' ';
    cout << endl;

    return 0;
}