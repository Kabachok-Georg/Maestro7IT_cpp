/*
    [ Sort and Star ]

    You will be given a list of strings.
    You must sort it alphabetically (case-sensitive, and based on the ASCII values of the chars) and then return the first value.
    The returned value must be a string, and have "***" between each of its letters.
    You should not remove or add elements from/to the array.
*/

#include <vector>
#include <string>
#include <algorithm>

std::string twoSort(std::vector<std::string> s)
{
    std::sort(s.begin(), s.end());
    std::string result = s[0];
    std::string formatted_result;
    for (size_t i = 0; i < result.size(); ++i)
    {
        formatted_result += result[i];
        if (i != result.size() - 1)
        {
            formatted_result += "***";
        }
    }
    return formatted_result;
}

/**
 * @brief Сортирует вектор строк и возвращает первую строку с разделением каждого символа "***".
 * 
 * Эта функция принимает вектор строк, сортирует его в порядке возрастания, а затем форматирует первую строку
 * в отсортированном векторе, вставляя "***" между каждым символом.
 * 
 * @param s Вектор строк для сортировки и форматирования.
 * @return Отформатированная строка, где каждый символ первой строки в отсортированном векторе разделен "***".
 */



// Авторы: Дуплей Максим и Данилов Георгий
// Дата: 22.12.2024