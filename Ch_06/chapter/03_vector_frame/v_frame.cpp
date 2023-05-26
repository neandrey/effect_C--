//рамочка вокруг vector<string>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string::size_type width(const vector<string>&);
vector<string> frame(const vector<string>&);
vector<string> vcat(const vector<string>&, const vector<string>&);
vector<string> hcat(const vector<string>&, const vector<string>&);
void print_vector(const vector<string>&);

int main() {

    vector<string> p;
    p.push_back("this is an");
    p.push_back("example");
    p.push_back("to");
    p.push_back("illustrate");
    p.push_back("framing");
    print_vector(p);

    vector<string> f = frame(p);
    print_vector(f);

    vector<string> h = hcat(frame(p), p);
    print_vector(h);

    return 0;
}

string::size_type width(const vector<string>& v) 
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());

    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // верхняя граница
    ret.push_back(border);

    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }
    // нижняя граница
    ret.push_back(border);
    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    // копируем верхнюю картинку.
    vector<string> ret = top;

    // копируем нижнюю картинку.
    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
        ret.push_back(*it);

    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    string::size_type width1 = width(left) + 1;

    vector<string>::size_type i = 0, j = 0;
    
    while (i != left.size() or j != right.size()) {

        string s;
        if (i != left.size())
            s = left[i++];
        
        s += string(width1 - s.size(), ' ');

        if (j != right.size())
            s += right[j++];

        ret.push_back(s);
    }
    return ret;
}

void print_vector(const vector<string> & v)
{
    for (auto i : v)
        cout << i << '\n';
    cout << endl;
}
