// Проблема кода.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student_info
{
    string name;
    double midterm, final;
    vector<double> homework;
};

int main() {

    string::size_type maxlen = 1;
    Student_info s;
    cout << max(s.name.size(), maxlen) << endl; // аргументы должны быть одного типа.

    return 0;
}