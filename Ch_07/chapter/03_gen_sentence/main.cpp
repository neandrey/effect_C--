#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "grammar.h"

using namespace std;

int main() {

    ifstream file;
    file.exceptions(ifstream::badbit);
    try {
        file.open("grammar_input.txt");
        
        vector<string> sentence = gen_sentence(read_grammar(file));

        vector<string>::const_iterator it = sentence.begin();
        if (!sentence.empty()) {
            cout << *it;
            ++it;
        }

        while (it != sentence.end()) {
            cout << " " << *it;
            ++it;
        }
        cout << endl;
    } catch (const ifstream::failure& e){
        cout << "Exception file bit";
    }

    file.close();
    return 0;
}