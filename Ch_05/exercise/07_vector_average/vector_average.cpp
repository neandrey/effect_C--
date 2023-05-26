// Высисление среднего арифметического.
#include <vector>
#include <iostream>
#include <stdexcept>
#include "average.h"

using namespace std;

int main() {

    vector<double> v_double = {1.0, 2.0, 3.0};

    try {
        cout << average(v_double) << endl; 
    } catch (invalid_argument e){
        cout << e.what();
    }
    cout << endl;

    return 0;
}