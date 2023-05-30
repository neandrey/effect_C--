// split 
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using std::vector;  using std::cout;
using std::endl;    using std::string;
using std::back_inserter;
using std::cin;     using std::getline;

// Возвращает true, если аргумент - пробел.
bool space(char c)
{
    return isspace(c);
} 

// Возвращает false, если аргумент - пробел.
bool not_space(char c)
{
    return !isspace(c);
}

namespace My_name{
template <class Out> 
void split(const string& str, Out os)
{
    typedef string::const_iterator iter;
    iter i = str.begin();
    while (i != str.end()){
        i = std::find_if(i, str.end(), not_space);
        iter j =  std::find_if(i, str.end(), space);

        if(i != str.end())
            *os++ = string(i, j);
        i = j;
    }
}
}

int main() {

    string s;
    while(getline(cin, s))
        My_name::split(s, std::ostream_iterator<string>(cout, "\n"));
  
    return 0;
}