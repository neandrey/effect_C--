#include "core.h"
#include "grade.h"

using std::string;
using std::vector;
using std::istream;


string Core::name() const { return n; }

double Core::grade() const
{
    return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in)
{
    in >> n >> midterm >> final; 
    return in;
}

istream& Core::read(istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}

istream& Grade::read(istream& in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, Core::homework);
    return in;
}

double Grade::grade() const
{
    return std::min(Core::grade(), thesis);
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

bool compare(const Core &c1, const Core &c2)
{
    return c1.name() < c2.name();
}

bool compare_grades(const Core &c1, const Core &c2)
{
    return c1.grade() < c2.grade();
}
