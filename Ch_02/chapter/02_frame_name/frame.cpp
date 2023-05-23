// Запрашивает имя пользователя
// генерирует приветствие в рамки

#include <iostream>
#include <string>
#include <vector>

int main() {

    std::cout << "Введите, пожалуйста, свое имя: ";
    std::string name;
    std::cin >> name;

    // Создаем сообщение подлежащее выводу.
    const std::string greeting = "Hello, " + name + "!";

    // Создаем 2 и 4 строки приветствия
    const std::string space(greeting.size(), ' ');
    const std::string second = "* " + space + " *";

    // Создаем 1 и 5 строку приветствия.
    const std::string first(second.size(), '*');

    // Выводим строки.
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    return 0;
}