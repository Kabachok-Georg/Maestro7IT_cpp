#include <iostream>
#include <cmath>
#include <limits>

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    int sqrtNum = static_cast<int>(std::sqrt(num));
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int number;
    std::cout << "Введите целое число: ";
    while (!(std::cin >> number) || std::cin.fail())
    {
        std::cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (isPrime(number))
    {
        std::cout << number << " является простым числом." << std::endl;
    }
    else
    {
        std::cout << number << " не является простым числом." << std::endl;
    }

    return 0;
}
