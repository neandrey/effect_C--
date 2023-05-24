// Вычисление оценок студентов.

#include <iomanip>
#include <iostream>
#include <string>
#include <ios>

using namespace std;

int main() {

    // Запрашиваем и считываем имя студента.
    cout << "Пожалуйста, введите свое имя: ";
    string name;
    cin >> name;
    cout << "Привет, " << name << "!" << endl;

    // оценки по экзаменам, проведенным в середине
    // и конце семестра.
    cout << "Пожалуйста, введите оценки по экзаменам "
            "в середине и в конце семестра: ";

    double midterm, final;
    cin >> midterm >> final;

    // оценки за домашние задания.
    cout << "Введите все оценки за выполненные домашние задания, "
            "завершите ввод признаком конца файла: ";

    int count = 0; // количество
    double sum = 0; // сумма

    double x; // считывание данных за дз.

    while (cin >> x) {
        ++count;
        sum += x;
    }

    //Вывод результата
    streamsize prec = cout.precision();
    cout << "Ваша итоговая оценка равна: " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * (sum/count)
         << setprecision(prec) << endl;

    return 0;
}