// Корректна ли программа
// если нет как сделать корректной? 
#include <iostream>
#include <string>


int main() {

    //first variant
    {   const std::string s = "одна строка"; 
    {   const std::string x = s + ", действительно"; // внутренняя переменная internal
        std::cout << s << std::endl;   
        std::cout << x << std::endl; // поместить вывод в эту область видимости.
    }
    }
    std::cout << '\n';

    //second variant
    {   const std::string s = "одна строка"; 
        std::string x; //объявить внешнюю
        {   
            x = s + ", действительно"; 
            std::cout << s << std::endl;   
        }
        std::cout << x << std::endl; 
    }

    return 0;
}