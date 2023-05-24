// Сколько раз каждое слово содержится в веденных данных.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    cout << "Введите слова, "
            "завершите ввод признаком конца файла.";
    
    string word;
    vector<string> words;

    while (cin >> word) {
        words.push_back(word);
    }

    if (words.empty()) {
        cout << endl << "Нет данных в векторе." << endl;
        return 1;
    }

    sort(words.begin(), words.end());

    int count_word = 1;

    for (auto it = words.begin(); it != words.end(); ++it) {
        if (*it == *(it+1))
            ++count_word;
        else {
            cout << "Количество слов: " << *it << " = " << count_word << endl;
            count_word = 1;
        }
    }

   

    return 0;
}