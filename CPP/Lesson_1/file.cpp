// Подключение необходимых библиотек
#include <iostream>
#include <iomanip>

// Использование стандартного пространства имен
using namespace std;

// Главная функция программы
int main() {
    double num = 3.14159;
    std::cout << "Число pi: " << std::setprecision(5) << num << std::endl;
    std::cout << "Это новая строка\n";
    return 0;
}
