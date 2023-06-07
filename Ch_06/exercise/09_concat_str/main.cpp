#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main() {

    vector<string> v_str;
    
    for (string temp; cin >> temp; )
        v_str.push_back(temp);

    string res = accumulate(v_str.begin(), v_str.end(), string());

    cout << res << endl;

    return 0;
}