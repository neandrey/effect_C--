// Какое из чисел больше.
#include <iostream>

using namespace std;

int main() {

    cout << "Введите два числа: ";
    int numb1, numb2;
    cin >> numb1 >> numb2;

    if (numb1 > numb2)
        cout << "Число " << numb1 << " > " << numb2 << endl;
    else if (numb1 < numb2)
        cout << "Число " << numb1 << " < " << numb2 << endl;
    else
        cout << "Числа равны." << endl;

    return 0;
}
