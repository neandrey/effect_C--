#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0)
        throw domain_error("Медиана пустого вектора");

    sort(v.begin(), v.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

int main() {

    vector<int> i_vec{1, 2, 3, 4, 5, 6};
    vector<double> d_vec{2, 2, 3, 3, 4};

    cout << median(i_vec) << endl;
    cout << median(d_vec) << endl;

    return 0;
}