// Поиск палиндрома.
#include <iostream>
#include <algorithm>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::equal;
using std::endl;

bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin()); 
}

int main() {

    string s = "rotor";
    string res = "Word " + s;

    if (is_palindrome(s)) {
        res += " is palindrome"; 
    } else {
        res += " not palindrome";
    }
    cout << res << endl;

    return 0;
}