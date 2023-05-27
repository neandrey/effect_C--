// произведение чисел из диапазона [1, 10)
#include <iostream>
using namespace std;

int main() {

    int res = 1;

    for (int i = 1; i != 10; ++i)
        res *= i;

    cout << res << endl;

    return 0;
}