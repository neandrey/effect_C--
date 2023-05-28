#include "grammar.h"
#include "split.h"

using std::map;         using std::istream;
using std::vector;      using std::string;
using std::logic_error; using std::domain_error;

Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    while (getline(in, line)) {
        vector<string> entry = split(line);

        if (!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;

}

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if (!bracketed(word)) {
        ret.push_back(word);
    } else {
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("пустое правило.");
        
        // Считываем набор возможных правил
        const Rule_collection& c = it->second;

        // из которых случайным образом выбираем одно.
        const Rule& r = c[nrand(c.size())];

        // рекурсивно заменяем выбранное правило
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

// Функция возвращает случайное целое число из диапазона [0, n)
int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Аргумент функции nrand вне диапазона.");
    
    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);

    return r;
}