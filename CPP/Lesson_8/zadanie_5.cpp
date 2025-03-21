/*
    🌟 Программа "Поиск экстремумов" 🌟

    Описание:
    Эта программа помогает найти максимальное и минимальное число в последовательности,
    введенной пользователем. Она идеально подходит для анализа данных, поиска рекордов
    или просто для того, чтобы удивить друзей своими навыками программирования!

    Как это работает:
    1. Вы вводите числа одно за другим.
    2. Когда захотите остановиться, введите -1.
    3. Программа мгновенно определит самое большое и самое маленькое число в вашей последовательности.

    Пример использования:
    Введите последовательность чисел (для завершения введите -1):
    10
    3
    7
    42
    15
    -1
    Максимальное число: 42
    Минимальное число: 3

    Автор: Ваше имя
    Версия: 1.0
    Дата: 2023-10-10
*/

#include <iostream>
#include <limits>

int main()
{
    int num;
    bool first = true;
    int min = 0;
    int max = 0;

    std::cout << "Введите числа:" << std::endl;

    while (std::cin >> num)
    {
        if (first)
        {
            min = num;
            max = num;
            first = false;
        }
        else
        {
            if (num < min)
            {
                min = num;
            }
            if (num > max)
            {
                max = num;
            }
        }
    }

    if (first)
    {
        std::cout << "Вы не ввели ни одного числа." << std::endl;
    }
    else
    {
        std::cout << "Минимальное число: " << min << std::endl;
        std::cout << "Максимальное число: " << max << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}
