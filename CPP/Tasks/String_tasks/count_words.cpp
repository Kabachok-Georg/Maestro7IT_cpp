#include <iostream>
#include <string>
#include <sstream>

/**
 * Подсчитывает количество слов в заданной строке.
 *
 * Эта функция принимает строку в качестве входных данных и возвращает количество слов в строке.
 *
 * @param inputString Строка, в которой нужно подсчитать слова.
 * @return Количество слов в строке.
 */
int countWords(const std::string &inputString)
{
    std::istringstream stream(inputString);
    return std::distance(std::istream_iterator<std::string>(stream),
                         std::istream_iterator<std::string>());
}

int main()
{
    std::string inputString;
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);
    int wordCount = countWords(inputString);
    std::cout << "Количество слов: " << wordCount << std::endl;
    return 0;
}
