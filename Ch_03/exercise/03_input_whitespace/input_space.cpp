// Ввод количество пробелов. 
#include <iostream>
#include <string>

using namespace std;

int main() {

    // Запрашиваем имя человека
    cout << "Введите, пожалуйста, свое имя: ";

    // Читаем введенное имя.
    string name;
    cin >> name;

    // сообщение подлежащее выводу
    const string greeting = "Hello, " + name + "!";

    // Количество пустых строк между приветствием и одной из
    // горизонтальных границ рамки.
    int pad = 0;
    cout << "Введите количество пробелов: ";
    cin >> pad;

    // Общее количество выводимых строк.
    const int rows = pad * 2 + 3;

    const string::size_type cols = greeting.size() + pad * 2 + 2;

    cout << endl;

    // выводим rows строк.
    int r = 0;

    // пока мы вывели r строк
    for (int r = 0; r != rows; ++r){
        string::size_type c = 0;
        while(c != cols){
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                if(r == 0 || r == rows-1 || c == 0 || c == cols -1) 
                    cout << "*";
                else 
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}