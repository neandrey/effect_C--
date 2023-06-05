// палиндромы
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <stdexcept>

using namespace std;

bool is_palindrom(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin()); 
}

bool compare(const string& s1, const string& s2)
{
    return s1.size() > s2.size();
}

string str_lower(const string& s)
{
    string res;
    for (auto i : s)
        res.push_back(tolower(i));

    return res;
}

int main() {

    vector<string> dict; 
    ifstream ist {"dict_file"};
    if (!ist) throw runtime_error("Ошибка открытия файла.");

    for (string temp; ist >> temp; ) {
        if (is_palindrom(str_lower(temp)))
            dict.push_back(temp);
        }

    sort(dict.begin(), dict.end(), compare);
    cout << *dict.begin() << endl;

    return 0;
}