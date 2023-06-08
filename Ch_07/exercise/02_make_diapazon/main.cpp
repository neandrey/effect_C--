#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include <map>
#include <fstream>

using std::cin;             using std::setprecision;     
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;
using std::map;             using std::runtime_error;
using std::ifstream;

int main() {
    
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;   // Длина самого длинного имени.
    map<char, int> sum_ch_marks;
    ifstream ifs {"input.txt"};
    if (!ifs) throw runtime_error("Ошибка открытия входного файла"); 
     

    // Считываем и сохраняем все данные об оценках студента.
    // Инвариант: вектор students содержит все записи,
    // прочитанные до сих пор.
    // max содержит длину самой длинной фамилии
    // name в структуре students.

    while (read(ifs, record)) {
        //Находим длину самой длинной фамилии.
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // Упорядочиваем записи с данными о студентах по алфавиту.
    sort(students.begin(), students.end(), compare);


    // Выводим фамилии и оценки.
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

        // Выводим фамилию, дополненную справа
        // maxlen + 1 символами.
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');

        // Вычисляем и выводим итоговую оценку.
        try {
            double final_grade = grade(students[i]);
            char letter_grade  = marks_letter(final_grade);
            sum_ch_marks[letter_grade]++;
            streamsize prec = cout.precision();
            cout << setprecision(3) << std::setw(4) << final_grade
                 << setprecision(2) << std::setw(2) << letter_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }
    cout << endl;

    cout << "Marks total" << endl;
    for(auto& i : sum_ch_marks)
        cout << std::setw(5) << i.first << std::setw(5) << i.second << endl;
    cout << endl;
    
    return 0;
}