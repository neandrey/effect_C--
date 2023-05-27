//программ выводящая текст hello.cpp

#include <iostream>

using namespace std;

int main() {

    cout << "#include <iostream>\n\n"
         << "int main() {\n"
         << "\tstd::cout << \"Привет, мир!\" << std::endl;\n"
         << "\treturn 0;\n"
         << "}" << endl;

    return 0;
}