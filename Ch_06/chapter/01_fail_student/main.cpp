#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;             using std::setprecision;     
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;

int main() {
    
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;   // Длина самого длинного имени.

    // Считываем и сохраняем все данные об оценках студента.
    // Инвариант: вектор students содержит все записи,
    // прочитанные до сих пор.
    // max содержит длину самой длинной фамилии
    // name в структуре students.

    while (read(cin, record)) {
        //Находим длину самой длинной фамилии.
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // Упорядочиваем записи с данными о студентах по алфавиту.
    sort(students.begin(), students.end(), compare);

    // Отделяем cдавших студентов от не cдавших
    // extract_fails(students);

    // Выводим фамилии и оценки cдавших студентов.
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

        // Выводим фамилию, дополненную справа
        // maxlen + 1 символами.
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');

        // Вычисляем и выводим итоговую оценку.
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}