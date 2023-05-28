// Напишите программу для вывода слов (из введенных даннх)
// строчными буквами, а после них - прописными буквами.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include "split.h"
#include "lower_upper.h"
#include <stdexcept>


using std::string;      using std::vector;
using std::getline;     using std::cin;
using std::cout;        using std::endl;
using std::tolower;     using std::toupper;
using std::ifstream;    using std::runtime_error;  


int main() {

    vector<string> v_str;
    string in_file = "low_up.txt";
    ifstream ist {in_file};
    if (!ist) throw runtime_error("Невозможно открыть входной файл");

    // Ввод строк из потока.
    for (string s; getline(ist, s); )
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