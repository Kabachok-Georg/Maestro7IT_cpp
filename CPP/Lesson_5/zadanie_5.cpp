#include <iostream>
#include <cstring> // Для работы со строками C-style

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    char result[20];

    std::strcpy(result, str1); // Копирование строки
    std::strcat(result, " ");  // Конкатенация строк
    std::strcat(result, str2);

    std::cout << "Результат: " << result << std::endl;

    std::cout << "Длина строки: " << std::strlen(result) << std::endl;

    return 0;
}