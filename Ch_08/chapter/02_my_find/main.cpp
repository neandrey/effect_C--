// find - последовательный доступ к элементу
#include <iostream>
#include <vector>
#include <string>

using std::vector;  using std::cout;
using std::endl;    using std::string;

template <class In, class X> 
In find(In begin, In end, const X& x)
{
    while (begin != end && *begin != x)
        ++begin;

    return begin;
}

int main() {
    
    vector<int> v_int {5, 3, 2, 1, 4};
    cout << *(find(v_int.begin(), v_int.end(), 5)) << endl; 

    vector<string> v_str {"hello", "my", "cat", "dog"};
    cout << *(find(v_str.begin(), v_str.end(), "cat")) << endl;
    
    return 0;
}