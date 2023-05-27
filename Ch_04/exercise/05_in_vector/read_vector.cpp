#include "read_vector.h" 

using std::istream; using std::vector;
using std::string;

istream &read(istream & in, vector<string> & v)
{
    if (in) {
        v.clear();

        string s;
        while (in >> s)
        {
            v.push_back(s);
        }
        in.clear();
    }
    return in;
}