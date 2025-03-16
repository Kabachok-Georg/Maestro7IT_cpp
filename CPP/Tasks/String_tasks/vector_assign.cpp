#include <vector>
#include <iostream>

int main()
{
    using namespace std;

    // Объявление векторов
    vector<int> v1, v2, v3, v4;

    // Константы для инициализации
    const int initialValues[] = {10, 20, 30, 40, 50};
    const int fillValue = 4;
    const size_t fillCount = 7;

    // Заполнение вектора v1 значениями
    for (int value : initialValues)
    {
        v1.push_back(value);
    }

    // Вывод содержимого вектора v1
    cout << "v1 = ";
    for (const auto &v : v1)
    {
        cout << v << " ";
    }
    cout << endl;

    // Использование assign для копирования элементов из v1 в v2
    v2.assign(v1.begin(), v1.end());
    cout << "v2 = ";
    for (const auto &v : v2)
    {
        cout << v << " ";
    }
    cout << endl;

    // Использование assign для заполнения вектора определённым количеством одинаковых элементов
    v3.assign(fillCount, fillValue);
    cout << "v3 = ";
    for (const auto &v : v3)
    {
        cout << v << " ";
    }
    cout << endl;

    // Использование assign с инициализатором списка
    v4.assign({5, 6, 7});
    cout << "v4 = ";
    for (const auto &v : v4)
    {
        cout << v << " ";
    }
    cout << endl;

    // Использование метода data() для получения указателя на внутренний массив данных вектора
    cout << "Указатель на данные v4: " << v4.data() << endl;

    // Использование метода back() для получения последнего элемента вектора
    cout << "Последний элемент в v1: " << v1.back() << endl;
    cout << "Последний элемент в v2: " << v2.back() << endl;
    cout << "Последний элемент в v3: " << v3.back() << endl;
    cout << "Последний элемент в v4: " << v4.back() << endl;

    // Дополнительные методы
    cout << "Максимальный размер v4: " << v4.max_size() << endl;
    cout << "Реверсивный итератор к началу v4: " << (v4.rend().base() - v4.begin()) << endl;
    v4.shrink_to_fit();
    cout << "Вместимость v4 после shrink_to_fit: " << v4.capacity() << endl;

    return 0;
}
