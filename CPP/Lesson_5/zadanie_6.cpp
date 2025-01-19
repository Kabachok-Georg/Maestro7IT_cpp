#include <iostream>
#include <cstring> // Для работы со строками C-style

int main() {
    char str1[] = "\nМороз и солнце; день чудесный!\nЕщё ты дремлешь, друг прелестный —\nПора, красавица, проснись:\nОткрой сомкнуты негой взоры\nНавстречу северной Авроры,\nЗвездою севера явись!";
    char str2[] = "Hello World";
    char result[1000]; // Выделяем больше памяти для результата

    std::strcpy(result, str1); // Копирование строки
    std::strcat(result, " ");  // Конкатенация строк (Объединение)
    std::strcat(result, str2);

    std::cout << "Результат: " << result << std::endl;

    std::cout << "Длина строки: " << std::strlen(result) << std::endl;

    return 0;
}
