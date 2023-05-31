// генирация оценок на основе букв.
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int number_grade(const char* letter)
{
    // цифровое представление оценки.
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    // символьное представление оценки
    static const char* const letters[] = {
        "A+", "A", "A-",
        "B+", "B", "B-",
        "C+", "C", "C-",
        "D", "F"
    };

    static const size_t nletters = sizeof(letters) / sizeof(*letters);

    for (size_t i = 0; i != nletters; ++i)
        if (*letter == *letters[i])
            return numbers[i];

    throw out_of_range("Неверные входные данные"); 
}

int main() {

    string letter;
    cin >> letter;

    try {
        cout << number_grade(letter.c_str()) << endl;
    } catch (out_of_range& e) {
        cout << e.what() << ' ' << letter << endl;
    }

    return 0;
}
