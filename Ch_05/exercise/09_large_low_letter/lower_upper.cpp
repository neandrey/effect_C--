#include "lower_upper.h"

using std::string;
using std::toupper;
using std::tolower;

string& to_upper(string & s)
{
    for (string::iterator it = s.begin(); it != s.end(); ++it)
        *it = toupper(*it);

    return s;
}

string& to_lower(string& s)
{
    for (string::iterator it = s.begin(); it != s.end(); ++it)
        *it = tolower(*it);

    return s;
}
