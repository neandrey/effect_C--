// копирование символов массива.
#include <iostream>
#include <cstring>

using namespace std;

char* duplicate_chars(const char* p)
{
    size_t length = strlen(p) + 1;
    char* result = new char[length];

    copy(p, p + length, result);

    return result;
}

int main() {

    char* arr {"hello my dear friend"};
    char* res;

    res = duplicate_chars(arr);

    cout << res << endl;
}