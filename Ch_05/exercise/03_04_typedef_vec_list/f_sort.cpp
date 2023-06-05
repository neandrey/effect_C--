#include "f_sort.h"
#include <algorithm>

using std::vector;
using std::list;
using std::sort;

void f_sort(vector<Student_info>& v)
{
    sort(v.begin(), v.end(), compare);
}

void f_sort(list<Student_info>& l)
{
    l.sort(compare);
}
