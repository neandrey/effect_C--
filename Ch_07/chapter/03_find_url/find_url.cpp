#include "find_url.h"
#include <algorithm>

using std::vector; using std::string;

vector<string> find_urls(const string &s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    // просмотр содержимого входных данных.
    while (b != e)
    {
        // поиск одной или нескольких букв, стояших
        // за буквосочетанием "://".
        b = url_beg(b, e);

        // если поиск удался...
        if (b != e) {

            iter after = url_end(b, e);

            ret.push_back(string(b, after));

            b = after;
        }
    }
    return ret;
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";

    typedef string::const_iterator iter;

    // итератор i отмечает местонахождение разделителя.
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e)
    {
        if (i != b && i + sep.size() != e) {
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
            {
                --beg;
            }
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        i += sep.size();
    }
    
    return e; 
}
