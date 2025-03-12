#include <iostream>
#include <string>

/**
 * Заменяет все вхождения одной подстроки на другую в заданной строке.
 *
 * Эта функция принимает строку и две подстроки в качестве входных данных. Она возвращает строку с
 * всеми вхождениями первой подстроки, замененными на вторую подстроку.
 *
 * @param inputString Исходная строка.
 * @param oldSubstring Подстрока, которую нужно заменить.
 * @param newSubstring Подстрока для замены.
 * @return Измененная строка с заменами.
 */
std::string replaceSubstring(const std::string &inputString, const std::string &oldSubstring, const std::string &newSubstring)
{
    std::string result = inputString;
    size_t pos = 0;
    while ((pos = result.find(oldSubstring, pos)) != std::string::npos)
    {
        result.replace(pos, oldSubstring.length(), newSubstring);
        pos += newSubstring.length();
    }
    return result;
}

int main()
{
    std::string inputString, oldSubstring, newSubstring;
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);
    std::cout << "Введите подстроку для замены: ";
    std::getline(std::cin, oldSubstring);
    std::cout << "Введите новую подстроку: ";
    std::getline(std::cin, newSubstring);
    std::string result = replaceSubstring(inputString, oldSubstring, newSubstring);
    std::cout << "Результат: " << result << std::endl;
    return 0;
}
