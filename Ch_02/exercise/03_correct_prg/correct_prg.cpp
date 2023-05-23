// Корректна ли программа
#include <iostream>
#include <string>
using namespace std;

// программа корректна так каждое имя находится в своей зоне видимости
// программа выводит две строки.
int main() {
    {   const string s = "одна строка";
        cout << s << endl;
    }

    {   const string s = "другая строка";
        cout << s << endl;  
    }

    return 0;
}