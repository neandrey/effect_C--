// исходный файл для функций, связанных со
// структурой Student_info.
#include "Student_info.h"
#include "grade.h"

using std::istream; using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);

    return is;
}

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();
        
        double x;
        while (in >> x)
            hw.push_back(x);

        in.clear(); 
    }

    return in;
}

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> pass, fail;
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
        if (fgrade(students[i]))
            fail.push_back(students[i]);
        else
            pass.push_back(students[i]);
    
    students = pass;
    return fail;
}