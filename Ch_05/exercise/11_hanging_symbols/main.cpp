// определяем свисающие или выступающие буквы.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool not_protruding(const char c)
{
    static const string pr_char = "b, d, f, h, k, l, t";

    return !(find(pr_char.begin(), pr_char.end(), c) != pr_char.end());
}

bool not_hanging(const char c)
{
    static const string hn_char = "g, j, p, q, y";

    return !(find(hn_char.begin(), hn_char.end(), c) != hn_char.end());
}

bool compare(const string& s1, const string& s2)
{
    return s1.size() > s2.size();
}

int main() {

    vector<string> dict;
    ifstream ifs {"input.txt"};
    if (!ifs) throw runtime_error("Ошибка открытия файла");

    for (string temp; ifs >> temp; ) {
        if (not_hanging and not_protruding)
            dict.push_back(temp);
    }

    sort(dict.begin(), dict.end(), compare);

    cout << dict.front() << endl;

    return 0;
}