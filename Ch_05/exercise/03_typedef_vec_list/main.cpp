#include <chrono>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include "Extract_fails.h" 
#include "../../Student_info/Student_info.h"
#include "../../Student_info/grade.h" 
#include "f_sort.h"

using std::cin;             using std::setprecision;     
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::list;

int main() {
    
    //typedef vector<Student_info> Students_data;
    typedef list<Student_info> Students_data;

    Students_data students;
    Student_info record;
    string::size_type maxlen = 0;   // Длина самого длинного имени.

    while (read(cin, record)) {
        //Находим длину самой длинной фамилии.
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    f_sort(students); 

    Students_data fails = extract_fails(students);

    for (auto i : students)
        cout << i.name << ' ' << grade(i) << endl;
    
    return 0;
}