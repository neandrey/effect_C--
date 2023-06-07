// исходный файл для функций, связанных со
// структурой Student_info.
#include "Student_info.h"
#include "median.h"
#include "grade.h"
#include <algorithm>
#include <stdexcept>
#include <numeric>

using std::istream; using std::vector;
using std::find;
using std::domain_error;
using std::endl;
using std::back_inserter;
using std::accumulate;

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

bool did_all_hw(const Student_info& s)
{
    return (find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}

double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

double grade_aux(const Student_info& s) {

    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }

}

double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size(); 
}


double averenge_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info> & students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), averenge_grade);
    return median(grades);
}

double optimistic_median(const Student_info &s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
                back_inserter(nonzero), 0);
    
    if(nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    return median(grades);
}

void write_analysis(std::ostream &out, 
                    const std::string &name, 
                    double analysis(const vector<Student_info>&),
                    const std::vector<Student_info> &did, 
                    const std::vector<Student_info> &didnt)
{
    out << name << ": median(did) = " << analysis(did)
        << ", median(didnt) = " << analysis(didnt) << endl;
}
