#include <iostream>
#include <string>

using namespace std;

/**
 * Подсчитывает количество гласных букв в заданной строке.
 *
 * Эта функция принимает строку в качестве входных данных и возвращает количество гласных (a, e, i, o, u, а, е, ё, и, о, у, ы, э, ю, я) в строке, независимо от их регистра.
 *
 * @param inputString Строка, в которой нужно подсчитать гласные.
 * @return Количество гласных в строке.
 */

int countVowels(const std::string &inputString)
{
    std::string vowels = "aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";
    int count = 0;
    for (char ch : inputString)
    {
        if (vowels.find(ch) != std::string::npos)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    std::string inputString;
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);
    int vowelCount = countVowels(inputString);
    std::cout << "Количество гласных: " << vowelCount << std::endl;
    return 0;
}
