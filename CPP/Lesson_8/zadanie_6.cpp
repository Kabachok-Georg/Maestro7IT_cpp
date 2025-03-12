/*
1. Калькулятор:

Описание: Напишите программу, которая запрашивает у пользователя два числа и операцию (+, -, *, /), а затем выводит результат.

Пример:

Введите первое число: 10
Введите второе число: 5
Введите операцию (+, -, *, /):*
Результат: 50
*/
#include <iostream>

int main()
{
    double num1, num2, result;
    char operation;
    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;
    std::cout << "Введите операцию (+, -, *, /): ";
    std::cin >> operation;

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            return 1;
        }
        break;
    default:
        std::cout << "Ошибка: неверная операция!" << std::endl;
        return 1;
    }

    std::cout << "Результат: " << result << std::endl;
    return 0;
}
