// Префикс std
#include <iostream>

using namespace std;

int main() {

    const int n = 5; // количество символов.
    int k = 0;
    while (k != n)
    {
        using std::cout; // использование в этом блоке 
        cout << "*";
        ++k;
    }
    std::cout << std::endl; // объявляем снова std
    return 0;
}