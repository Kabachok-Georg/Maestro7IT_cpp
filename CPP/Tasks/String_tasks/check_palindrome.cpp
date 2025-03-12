#include <iostream>
#include <string>
#include <algorithm>

/**
 * Проверяет, является ли заданная строка палиндромом.
 *
 * Эта функция принимает строку в качестве входных данных и возвращает true, если строка является палиндромом,
 * и false в противном случае.
 *
 * @param inputString Строка для проверки.
 * @return True, если строка является палиндромом, false в противном случае.
 */
bool isPalindrome(const std::string &inputString)
{
    std::string cleanedString;
    for (char ch : inputString)
    {
        if (std::isalnum(ch))
        {
            cleanedString += std::tolower(ch);
        }
    }
    std::string reversed = cleanedString;
    std::reverse(reversed.begin(), reversed.end());
    return cleanedString == reversed;
}

int main()
{
    std::string inputString;
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);
    if (isPalindrome(inputString))
    {
        std::cout << "Строка является палиндромом." << std::endl;
    }
    else
    {
        std::cout << "Строка не является палиндромом." << std::endl;
    }
    return 0;
}
