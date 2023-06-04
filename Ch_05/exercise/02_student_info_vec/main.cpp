#include <chrono>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Extract_fails.h" 
#include "../../Student_info/Student_info.h"
#include "../../Student_info/grade.h" 

using std::cin;             using std::setprecision;     
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::microseconds;



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

    //для замера производительности
    auto start = high_resolution_clock::now();

    // Отделяем cдавших студентов от не cдавших
    vector<Student_info> fails = extract_fails(students);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Время работы extract_fails "
         << duration.count() << " microseconds." << endl;
    
    for (vector<Student_info>::size_type i = 0; i != fails.size(); ++i)
        cout << fails[i].name << " " << grade(fails[i]) << endl;
    
    return 0;
}