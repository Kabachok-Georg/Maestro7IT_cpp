#include <iostream>

void divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Деление на ноль!");
    }
    std::cout << "Результат: " << a / b << std::endl;
}

int main() {
    try {
        divide(10, 2); // Нормальная работа
        divide(10, 0); // Генерация исключения
    } catch (const std::exception &e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}