// указатели на функцию
#include <iostream>

using namespace std;

int next(int n)
{
    return n + 1;
}

int main() {

    int i = 0;
    int (*fp)(int); // указатель на функцию.

    fp = next;

    cout << "i = " << i << endl;

    i = fp(i);

    cout << "i = " << i << endl;
    
    return 0;
}