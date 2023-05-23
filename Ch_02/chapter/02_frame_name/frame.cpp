// Запрашивает имя пользователя
// генерирует приветствие в рамки

#include <iostream>
#include <string>

std::size_t strlen_utf8(const std::string& str) {
	std::size_t length = 0;
	for (char c : str) {
		if ((c & 0xC0) != 0x80) {
			++length;
		}
	}
	return length;
}

int main() {

    std::cout << "Введите, пожалуйста, свое имя: ";
    std::string name;
    std::cin >> name;

    // Создаем сообщение подлежащее выводу.
    const std::string greeting = "Привет, " + name + "!";

    size_t l_greeting = strlen_utf8(greeting);

    // Создаем 2 и 4 строки приветствия
    const std::string space(l_greeting, ' ');
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