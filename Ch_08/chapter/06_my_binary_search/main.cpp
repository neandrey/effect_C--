// binary_search
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::vector;  using std::cout;
using std::endl;    using std::string;
using std::back_inserter;

namespace My_name{
template <class Ran, class X> 
bool binary_search(Ran beg, Ran end, const X& x)
{
    while (beg != end){
        // средняя точка диапазона
        Ran mid = beg + (end - beg) / 2;

        if (x < *mid)
            end = mid;
        else if (*mid < x)
            beg = mid + 1;
        else
            return true;
    }
    return false;
}
}

int main() {
    
    vector<int> v_int {1, 2, 3, 4, 5};
    cout << My_name::binary_search(v_int.begin(), v_int.end(), 4) << endl; 
    
    return 0;
}