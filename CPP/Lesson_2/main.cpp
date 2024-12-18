/*
    Вычисление суммы и среднего двух чисел с выводом их сравнения.

    [ Входные данные ]
    Программа не принимает входные данные от пользователя напрямую (данные жестко закодированы в коде программы).
    
    Для данного примера входные данные:
    a = 15
    b = 20

    [ Выходные данные ]
    Программа выводит следующие данные:
    Первое значение: 15
    Второе значение: 20
    Сумма: 35
    Среднее значение: 17.5
    15 меньше 20

    ▶️ Этот код демонстрирует базовые операции, такие как арифметическое сложение, вычисление среднего значения, и использование операторов сравнения.
*/

#include <iostream>

int main() {
    int a = 15;
    int b = 20;
    std::cout << "Первое значение: " << a << std::endl;
    std::cout << "Второе значение: " << b << std::endl;
    int sum = a + b;
    float average = sum / 2.0;
    
    std::cout << "Сумма: " << sum << std::endl;
    std::cout << "Среднее значение: " << average << std::endl;
    
    if (a < b) {
        std::cout << a << " меньше " << b << std::endl;
    } else {
        std::cout << a << " больше " << b << std::endl;
    }

    return 0;
}
