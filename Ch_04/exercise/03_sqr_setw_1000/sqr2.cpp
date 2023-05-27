// Программа вычисляющая квадраты int-значений до 1000.
#include <iostream>
#include <iomanip>

using namespace std;

int length(int n);

int main() {

    const int numb = 1000;

    for (int i = 0; i != numb; ++i)
        cout << setw(length(numb)) << i << setw(length(numb * numb)) << i*i << endl;

    return 0;
}

int length(int n)
{
    int l = 0;

    while (n > 0){
        n /= 10;
        ++l;
    }

    return l;
}
