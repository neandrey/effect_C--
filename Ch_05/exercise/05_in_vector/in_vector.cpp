// Считывание значений из потока в вектор.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "read_vector.h" 

using std::vector;  using std::cout;
using std::string;  using std::cin;
using std::endl;


int main() {

    vector<string> res;
    size_t count_word = 0;

    read(cin, res);

    cout << "Количество слов в входном потоке: " << res.size() << endl;

    sort(res.begin(), res.end());

    for (auto it = res.begin(); it != res.end(); ++it) {
        if (*it == *(it+1))
            ++count_word;
        else {
            cout << "Количество слов: " << *it << " = " << count_word << endl;
            count_word = 1;
        }
    }

    return 0;
}