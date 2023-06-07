// Исходный файл для функции median.
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <numeric>


using std::domain_error;
using std::sort;
using std::vector;
using std::back_inserter;
using std::accumulate;

double median(vector<double> vec) {
    
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();

    if(size == 0)
        throw domain_error("Медиана пустого вектора.");
    
    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

// double averages(const vector<double>& v)
// {
//     return accumulate(v.begin(), v.end(), 0.0) / v.size(); 
// }
