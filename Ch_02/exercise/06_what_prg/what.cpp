//Что делает следующая программа.
#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "Как вас зовут? ";
    string name;
    cin >> name;
    cout << "Привет, " << name
         << endl << "А как вас зовут? ";
    
    cin >> name;
    cout << "Привет, " << name
         << "; с вами тоже было приятно познокомиться!"
         << endl;
    
    return 0;
}