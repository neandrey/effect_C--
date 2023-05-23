// Допустимы ли следующие определения? почему?

#include <iostream>
using namespace std;

int main() {

    const string exclam = "!";
    const string message = "Привет" + ", мир" + exclam; // недопустима, потомучто два символьных литерала.

    cout << exclam << endl
         << message << endl;
    
    return 0;
}