#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size())
    {
        while (i != s.size() and isspace(s[i]))
            ++i;

        string_size j = i;
        while (j != s.size() and !isspace(s[j]))
            ++j;

        if (i != j){
            ret.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return ret;
}

int main() {

    string s;
    // Считываем и разбираем на слова каждую вводимую строку.
    while (getline(cin, s))
    {
        vector<string> v = split(s);

        for (vector<string>::size_type i = 0; i != v.size(); ++i)
            cout << v[i] << endl;
    }
    return 0;
}