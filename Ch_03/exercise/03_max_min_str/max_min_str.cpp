// Самая длинная, короткая строка.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    cout << "Введите любое количество слов "
            "завершите ввод признаком окончания файла.";

    string word;
    vector<string> words;

    while (cin >> word) {
        words.push_back(word);
    }

    if (words.empty()) {
        cout << "Вектор пустой." << endl;
        return 1;
    }

    sort(words.begin(), words.end(), [](const string& first, const string& second){
        return first.size()  < second.size();
    });

    cout << "min value = " << words[0].size() << " max value = " << words[words.size()-1].size() << endl;

    return 0;
}
