#include <iostream>

int main()
{
    double num1, num2, num3;

    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;
    std::cout << "Введите третье число: ";
    std::cin >> num3;

    double max = num1;
    if (num2 > max)
    {
        max = num2;
    }
    if (num3 > max)
    {
        max = num3;
    }

    std::cout << "Наибольшее число: " << max << std::endl;

    return 0;
}
