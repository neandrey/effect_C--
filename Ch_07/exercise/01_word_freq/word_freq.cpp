// Подсчет слов
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string s;
    map<string, int> counters; // храним слово - счетчик
    map<int, string> sort_counters;

    // Считываем данные.
    while (cin >> s)
        ++counters[s];

    for (auto it : counters)
        sort_counters[it.second] = it.first;
    

    // Выводим результат
    for (auto it : sort_counters) {
        cout << it.second << "\t" << it.first << endl;
    }

    return 0;
}