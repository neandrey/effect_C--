#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using std::string; using std::cin;
using std::vector; using std::cout;
using std::endl;

// Возвращает true, если аргумент - пробел.
bool space(char c)
{
    return isspace(c);
} 

// Возвращает false, если аргумент - пробел.
bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {

        // игнорируем ведущие пробелы.
        i = find_if(i, str.end(), not_space);

        // находим конец следующего слова.
        iter j = find_if(i, str.end(), space);

        // копируем символы из диапазона [i, j).
        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}

int main() {

    string s;
    // Считываем и разбираем на слова каждую вводимую строку.
    while (getline(cin, s))
    {
        vector<string> v = split(s);

        for (auto i : v)
            cout << i << endl;
    }
    return 0;
}


