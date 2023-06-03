#include <iostream>
#include "vec.h"

using std::cout; using std::cin;
using std::endl;

int main() {

    Vec<int> v (10, 1);

    v.push_back(10);

    for (auto i : v) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}