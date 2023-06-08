#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <array>

using std::domain_error; using std::vector;
using std::string; using std::array;

double grade(const Student_info &s)
{
    return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, const vector<double> &hw)
{
    if(hw.size() == 0)
        throw domain_error("Студент не сделал ни одного домашнего задания.");
    return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

char marks_letter(double d)
{
    /*  
    A 90-100 
    B 80-89.99 
    C 70-79.99 
    D 60-69.99
    F > 60
    */

    vector<int> i_marks     {60, 70, 80, 90};
    vector<char> c_marks    {'D', 'C', 'B', 'A'};
    char letter_marks = 'F';
    
    for (size_t i = 0;  i != i_marks.size(); ++i) {
        if(d > i_marks[i]) {
            letter_marks = c_marks[i]; 
        }
    }

    return letter_marks;
    
}