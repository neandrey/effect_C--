#include <iostream>
#include <vector>
#include <string>
#include "Student_info.h"
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <fstream>

using std::vector;  using std::string;
using std::cout;    using std::endl;
using std::cin;     using std::max;
using std::streamsize;
using std::setprecision;
using std::domain_error;
using std::ifstream;
using std::runtime_error;

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    ifstream ifs {"input.txt"};
    if (!ifs) throw runtime_error {"Невозможно открыть файл"};


    // Считываем данные о студенте.
    while(record.read(ifs)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(begin(students), end(students), compare);

    // выводим данные
    // если студент не сделал домашние работы
    // то обрабатываем это как 0 оценку в
    // функции calc_grade;
    for (vector<Student_info>::size_type i = 0; 
         i != students.size(); ++i) {
        
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');
        
        double final_grade = students[i].grade();
        streamsize prec = cout.precision();
        cout << setprecision(3) << final_grade
                << setprecision(prec) << endl;
        
    }
    return 0;
}