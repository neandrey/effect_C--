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

istream& Student_info::read(istream& is)
{
    delete cp;

    char ch;
    is >> ch;

    if (ch == 'U') {
        cp = new Core(is);
    } else {
        cp = new Grade(is);
    }

    return is;
}

Student_info::Student_info(const Student_info& s): cp{0}
{
    if (s.cp)
        cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s)
{
    if (&s != this) {
        delete cp;
        if (s.cp)
            cp = s.cp->clone();
        else
            cp = 0;
    }
    return *this;
}



