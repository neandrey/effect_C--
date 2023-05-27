// Запрашиваем имя человека и приветствуем его.
#include <iostream>
#include <string>

int main() {
    std::cout << "Введите пожалуйста свое имя: ";

    std::string name;
    std::cin >> name;

    std::cout << "Привет, " << name << "!" << std::endl;
    return 0;
}