// replace 
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::vector;  using std::cout;
using std::endl;    using std::string;
using std::back_inserter;

namespace My_name{
template <class For, class X> 
void replace(For beg, For end, const X& x, const X& y)
{
    while (beg != end)
    {
        if (*beg == x)
            *beg = y;
        ++beg;
    }
}
}

int main() {
    
    vector<int> v_int {5, 3, 2, 1, 4};
    My_name::replace(v_int.begin(), v_int.end(), 5, 3); 

    for (auto i : v_int)
        cout << i << ' ';
    cout << endl;

    
    return 0;
}