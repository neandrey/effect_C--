// Поиск адресов url
#include <iostream>
#include <vector>
#include <string>
#include "find_url.h"

using std::string;  using std::vector;
using std::cout;    using std::cin;   
using std::endl;

int main() {

    string s = "http://google.com"; 
    vector<string> res;

    res = find_urls(s);

    for (auto i : res) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}