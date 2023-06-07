#include <iostream>
#include <vector>
#include <string>
#include "grade.h"
#include "Student_info.h"
#include "median.h"

using std::vector; using std::string;
using std::cout;    using std::cin;
using std::endl;

int main() {
    vector<Student_info> did, didnt;
    Student_info student;

    while (read(cin, student))
    {
        if(did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    if (did.empty()) {
        cout << "Ни один студент не выполнил всех домашних работ."
             << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "Все студенты выполнили все домашние задания."
             << endl;
        return 1;
    }

    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in",
                   optimistic_median_analysis, did, didnt); 

    return 0;
}