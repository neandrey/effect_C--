// Программа вычисляющая квадраты int-значений до 100.
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    for (int i = 0; i != 100; ++i)
        cout << setw(3) << i << setw(5) << i*i << endl;

    return 0;
}