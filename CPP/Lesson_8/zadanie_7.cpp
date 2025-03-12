#include <iostream>

int main()
{
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;

    if (number % 2 == 0)
    {
        std::cout << "Число " << number << " четное." << std::endl;
    }
    else
    {
        std::cout << "Число " << number << " нечетное." << std::endl;
    }

    return 0;
}
