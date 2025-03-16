/*
  Сортировка массива

  Описание: Напишите программу, которая сортирует массив чисел по возрастанию (используйте алгоритм пузырьковой сортировки).

  📄 Пример:
  Введите элементы массива: 10 3 7 42 15
  Отсортированный массив: 3 7 10 15 42
*/

#include <iostream>
#include <vector>

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

int main()
{
    std::vector<int> array = {10, 3, 7, 42, 15};

    bubbleSort(array);

    std::cout << "Отсортированный массив: ";
    for (int num : array)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
