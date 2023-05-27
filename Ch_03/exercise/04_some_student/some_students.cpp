// Вычисление оценок студентов - медианная.

#include <iomanip>
#include <iostream>
#include <string>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string name;
    vector<string> names;

    // Запрашиваем и считываем имя студента.
    cout << "Пожалуйста, введите имя студента: ";
    
    while (cin >> name) {
        names.push_back(name);

        cout << "Привет, " << name << "!" << endl;

        const int count_marks = 5;
        // оценки за домашние задания.
        cout << "Введите " << count_marks << " оценки за выполненные домашние задания";

        vector<double> homework;
        double x = 0;

        for (int i = 0; cin >> x and i != count_marks ;++i) {
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
         << 0.4 * median 
         << setprecision(prec) << endl;

    return 0;
}