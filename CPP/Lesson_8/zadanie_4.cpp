#include <iostream>
#include <string>
#include <algorithm>

// Функция для проверки, является ли строка палиндромом
bool isPalindrome(const std::string &str)
{
    int left = 0;
    int right = str.size() - 1;

    while (left < right)
    {
        // Пропуск неалфавитных символов слева
        if (!std::isalnum(str[left]))
        {
            left++;
            continue;
        }
        // Пропуск неалфавитных символов справа
        if (!std::isalnum(str[right]))
        {
            right--;
            continue;
        }
        // Сравнение символов (без учета регистра)
        if (std::tolower(str[left]) != std::tolower(str[right]))
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    // Вывод оригинальной строки
    std::cout << "Оригинальная строка: \"" << input << "\"" << std::endl;

    // Вывод строки в обратном порядке
    std::string reversed = input;
    std::reverse(reversed.begin(), reversed.end());
    std::cout << "Строка в обратном порядке: \"" << reversed << "\"" << std::endl;

    // Проверка, является ли строка палиндромом
    if (isPalindrome(input))
    {
        std::cout << "Строка является палиндромом." << std::endl;
    }
    else
    {
        std::cout << "Строка не является палиндромом." << std::endl;
    }

    return 0;
}