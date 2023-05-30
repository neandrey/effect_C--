// copy 
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::vector;  using std::cout;
using std::endl;    using std::string;
using std::back_inserter;

namespace My_name{
template <class In, class Out> 
Out copy(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;

    return dest;
}
}

int main() {
    
    vector<int> v_int {5, 3, 2, 1, 4};
    vector<int> cp_v_int;
    My_name::copy(v_int.begin(), v_int.end(), back_inserter(cp_v_int)); 

    for (auto i : cp_v_int)
        cout << i << ' ';
    cout << endl;

    
    return 0;
}