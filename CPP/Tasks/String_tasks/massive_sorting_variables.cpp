/*
  Вариативная сортировка массива

  Описание: Напишите программу, которая сортирует массив чисел по возрастанию (используйте алгоритмы различных сортировок - по выбору пользователя).

  📄 Пример:
  Введите элементы массива: 10 3 7 42 15
  Выберите вид сортировки: пузырьковая, шейкерная, расчёской, вставками
  Отсортированный массив: 3 7 10 15 42
*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <chrono>

/**
 * Пузырьковая сортировка.
 * Сравнивает каждый элемент с последующим и меняет их местами, если они находятся в неправильном порядке.
 *
 * @param arr Вектор целых чисел, который нужно отсортировать.
 */
void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/**
 * Шейкерная сортировка.
 * Улучшенная версия пузырьковой сортировки, которая проходит массив в обоих направлениях.
 *
 * @param arr Вектор целых чисел, который нужно отсортировать.
 */
void shakerSort(std::vector<int> &arr)
{
    int n = arr.size();
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

/**
 * Сортировка расчёской.
 * Улучшенная версия пузырьковой сортировки, которая использует большой шаг для устранения "черепах".
 *
 * @param arr Вектор целых чисел, который нужно отсортировать.
 */
void combSort(std::vector<int> &arr)
{
    int n = arr.size();
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i < n - gap; ++i)
        {
            if (arr[i] > arr[i + gap])
            {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

/**
 * Сортировка вставками.
 * Строит отсортированный массив, сравнивая каждый элемент с уже отсортированными.
 *
 * @param arr Вектор целых чисел, который нужно отсортировать.
 */
void insertionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    std::vector<int> array;
    int num;
    std::string sortType;

    std::cout << "Введите элементы массива (введите любой нечисловой символ для завершения ввода): ";
    while (std::cin >> num)
    {
        array.push_back(num);
    }

    std::cin.clear();                                                   // Очистка ошибки ввода
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорирование оставшихся символов

    std::cout << "Выберите вид сортировки (пузырьковая, шейкерная, расчёской, вставками): ";
    std::cin >> sortType;

    if (sortType == "пузырьковая")
    {
        bubbleSort(array);
    }
    else if (sortType == "шейкерная")
    {
        shakerSort(array);
    }
    else if (sortType == "расчёской")
    {
        combSort(array);
    }
    else if (sortType == "вставками")
    {
        insertionSort(array);
    }
    else
    {
        std::cout << "Неизвестный вид сортировки." << std::endl;
        return 1;
    }

    std::cout << "Отсортированный массив: ";
    for (int num : array)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
