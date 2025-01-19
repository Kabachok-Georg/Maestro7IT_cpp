#include <iostream>
#include "functions.h"

int main() {
    int x, y;
    std::string s; // Change to string to accept operators like "+" and "-"

    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;
    std::cout << "Введите символ для действия: ";
    std::cin >> s;

    if (s == "+") {
        std::cout << "Сумма: " << add(x, y) << std::endl;
    } else if (s == "-") { // Use else if instead of if else
        std::cout << "Разность: " << subtract(x, y) << std::endl;
    } else if (s == "*") { // Change to else if and remove the semicolon
        std::cout << "Произведение: " << multiply(x, y) << std::endl;
    } else if (s=="/"){
        std::cout << "Деление: " << divide(x, y) << std::endl;     
    } else {
        std::cout << "Неизвестное действие." << std::endl; // Handle unknown operator
    }

    return 0;
}
