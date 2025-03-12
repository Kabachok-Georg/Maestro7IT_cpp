#include <iostream>
#include <string>
#include <algorithm>

/**
 * Переворачивает заданную строку.
 *
 * Эта функция принимает строку в качестве входных данных и возвращает перевернутую строку.
 *
 * @param inputString Строка для переворота.
 * @return Перевернутая строка.
 */
std::string reverseString(const std::string &inputString)
{
    std::string reversed = inputString;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

int main()
{
    std::string inputString;
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);
    std::string reversedString = reverseString(inputString);
    std::cout << "Перевернутая строка: " << reversedString << std::endl;
    return 0;
}
