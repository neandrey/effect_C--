// Допустимы ли следующие определения? почему?

#include <iostream>
using namespace std;

int main() {

    const string hello = "Привет";
    const string message = hello + ", мир" + "!";

    cout << hello << endl
         << message << endl;
    
    return 0;
}