#include <iostream>
#include "Str.h"

using std::cout;
using std::cin;
using std::endl;


int main() {

    Str s{"hello"};

    cout << s << endl;

    cin >> s;

    Str greeting = "Привет, " + s + "!";

    cout << greeting << endl;
    
    return 0;
}