// Различное количество пробелов между приветствием и боковыми сторонами.
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
    const int top_bottom_side = 5;
    const int left_right_side = 1;

    // Общее количество выводимых строк.
    const int rows = top_bottom_side * 2 + 3;

    const string::size_type cols = greeting.size() + left_right_side * 2 + 2;

    cout << endl;

    // выводим rows строк.
    int r = 0;

    // пока мы вывели r строк
    for (int r = 0; r != rows; ++r){
        string::size_type c = 0;
        while(c != cols){
            if (r == top_bottom_side + 1 && c == left_right_side + 1) {
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