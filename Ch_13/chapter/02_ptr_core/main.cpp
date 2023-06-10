#include <iostream>
#include <string>
#include "core.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <fstream>

using std::cin;     using std::cout;
using std::endl;    using std::vector;
using std::string;  using std::streamsize;
using std::sort;    using std::setprecision;
using std::domain_error;
using std::ifstream;
using std::runtime_error;

int main() {

    ifstream ifs {"input.txt"};
    if (!ifs) throw runtime_error {"Невозможно открыть файл"};
    
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    //Считываем и сохраняем данные.
    while (record.read(ifs)) {
        maxlen = std::max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), Student_info::compare);

    for (vector<Student_info>::size_type i = 0;
                        i != students.size(); ++i) {
        
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(),
                       ' ');

        try {
            double final_grade = students[i].grade(); 
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec) << endl; 
        } catch(domain_error e){
            cout << e.what() << endl;
        }

    }
    return 0;
}