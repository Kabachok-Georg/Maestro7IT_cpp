/*
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
*/

#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    const int size = 2;
    int x[size], y[size];
    std::string s; 

    
    for (int i = 0; i < size; ++i) {
        std::cout << "Введите число x[" << i << "]: ";
        std::cin >> x[i];
        std::cout << "Введите число y[" << i << "]: ";
        std::cin >> y[i];
    }

    std::cout << "Введите символ для действия: ";
    std::cin >> s;

    for (int i = 0; i < size; ++i) {
        if (s == "+") {
            std::cout << "Сумма: " << add(x[i], y[i]) << std::endl;
        } else if (s == "-") {
            std::cout << "Разность: " << subtract(x[i], y[i]) << std::endl;
        } else if (s == "*") {
            std::cout << "Произведение: " << multiply(x[i], y[i]) << std::endl;
        } else if (s == "/") {
            std::cout << "Деление: " << divide(x[i], y[i]) << std::endl;     
        } else {
            std::cout << "Неизвестное действие." << std::endl;
        }
    }

    return 0;
}