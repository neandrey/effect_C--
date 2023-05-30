// reverse
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::vector;  using std::cout;
using std::endl;    using std::string;
using std::back_inserter;

namespace My_name{
template <class Bi> 
void reverse(Bi beg, Bi end)
{
    while (beg != end){
        --end;
        if(beg != end)
            std::swap(*beg++, *end);
    }
        
}
}

int main() {
    
    vector<int> v_int {5, 3, 2, 1, 4};
    My_name::reverse(v_int.begin(), v_int.end()); 

    for (auto i : v_int)
        cout << i << ' ';
    cout << endl;

    
    return 0;
}