/*
    [Find Maximum and Minimum Values of a List(8 kyu)]

    Your task is to make two functions, max and min (maximum and minimum in PHP and Python,
    maxi and mini in Julia) that take a(n) array/vector of integers list as input and outputs,
    respectively, the largest and lowest number in that array/vector.

    Examples
    * [4,6,2,1,9,63,-134,566]         -> max = 566, min = -134
    * [-52, 56, 30, 29, -54, 0, -110] -> min = -110, max = 56
    * [42, 54, 65, 87, 0]             -> min = 0, max = 87
    * [5]                             -> min = 5, max = 5
*/

#include <vector>
#include <algorithm>

using namespace std;

int min(vector<int> list) {
    return *min_element(list.begin(), list.end());
}

int max(vector<int> list) {
    return *max_element(list.begin(), list.end());
}

/**
 * @brief Находит минимальное значение в списке целых чисел.
 * 
 * Эта функция принимает вектор целых чисел и возвращает наименьшее
 * целое число в списке, используя функцию `min_element` из стандартной
 * библиотеки.
 * 
 * @param list Вектор целых чисел.
 * @return Наименьшее целое число в списке.
 */

// Авторы: Дуплей Максим и Данилов Георгий
// Дата: 18.12.2024