/* 10.2 median 
    функция должна быть способна
    обрабатывать контейнеры любого 
    арифметическог типа.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<class T, class Iter>
T median(Iter beg, Iter end)
{
   if (beg == end) 
        throw domain_error("Медиана пустого контейнера");

    vector<T> temp;

    copy(beg, end, back_inserter(temp));
    sort(temp.begin(), temp.end());

    typename vector<T>::size_type mid = temp.size() / 2;

    return temp.size() % 2 == 0 ? (temp[mid] + temp[mid-1]) / 2 
                                                : temp[mid];
}

int main() {

    vector<int> i_vec {1, 2, 3, 4, 5, 6};
    int i_array[] {1, 2, 3, 4, 5, 6};


    cout << median<int, vector<int>::iterator>(i_vec.begin(), i_vec.end()) << endl;
    cout << median<int, int*>(begin(i_array), end(i_array)) << endl;

    return 0;
}