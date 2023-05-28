// Подсчет слов
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string s;
    map<string, int> counters; // храним слово - счетчик

    // Считываем данные.
    while (cin >> s)
        ++counters[s];

    // Выводим результат
    for (auto it : counters) {
        cout << it.first << "\t" << it.second << endl;
    }

    return 0;
}