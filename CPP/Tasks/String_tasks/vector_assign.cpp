// vector_assign.cpp
// Программа демонстрирует использование метода assign для векторов в C++.
// Компиляция: /EHsc

#include <vector>
#include <iostream>

int main()
{
    using namespace std;

    // Объявление векторов
    vector<int> v1, v2, v3;

    // Заполнение вектора v1 значениями
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    // Вывод содержимого вектора v1
    cout << "v1 = ";
    for (const auto &v : v1)
    {
        cout << v << " ";
    }
    cout << endl;

    /**
     * Использование assign для копирования элементов из одного вектора в другой.
     * v2.assign(v1.begin(), v1.end()) копирует все элементы из v1 в v2.
     */
    v2.assign(v1.begin(), v1.end());
    cout << "v2 = ";
    for (const auto &v : v2)
    {
        cout << v << " ";
    }
    cout << endl;

    /**
     * Использование assign для заполнения вектора определённым количеством одинаковых элементов.
     * v3.assign(7, 4) заполняет v3 семью четвёрками.
     */
    v3.assign(7, 4);
    cout << "v3 = ";
    for (const auto &v : v3)
    {
        cout << v << " ";
    }
    cout << endl;

    /**
     * Использование assign с инициализатором списка.
     * v3.assign({ 5, 6, 7 }) заменяет содержимое v3 на {5, 6, 7}.
     */
    v3.assign({5, 6, 7});
    cout << "v3 = ";
    for (const auto &v : v3)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
