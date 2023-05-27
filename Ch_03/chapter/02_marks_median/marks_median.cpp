// Вычисление оценок студентов - медианная.

#include <iomanip>
#include <iostream>
#include <string>
#include <ios>
#include <vector>
#include <algorithm>

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

    vector<double> homework;
    

    double x; // считывание данных за дз.

    while (cin >> x) {
        homework.push_back(x);
    }
    
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    if (size == 0) {
        cout << endl << "Вектор оценок пуст.";
        return 1;
    }

    sort(homework.begin(), homework.end());

    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
                           : homework[mid];

    //Вывод результата
    streamsize prec = cout.precision();
    cout << "Ваша итоговая оценка равна: " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median 
         << setprecision(prec) << endl;

    return 0;
}