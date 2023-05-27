//среднее арифметическое из vector<double>
#include"average.h"
#include <stdexcept> 

using std::vector; using std::invalid_argument;

double average(const vector<double>& v)
{
    vector<double>::size_type v_size = v.size(); 
    if (!v_size) throw invalid_argument("Деление на ноль."); 
    double sum = 0;
    for (auto i : v) {
        sum += i;
    }

    return sum / v_size;

}