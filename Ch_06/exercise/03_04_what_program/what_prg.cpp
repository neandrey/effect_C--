// Что делает этот фрагмент программы?
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {

    vector<int> u(10, 100); // 10 - элементов со значением 100
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));   

    for (auto i : v)
        cout << i << endl;
    cout << endl;

    return 0;
}