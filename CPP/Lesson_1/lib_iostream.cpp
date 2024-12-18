/*
    📖 iostream — это стандартная библиотека C++ для работы с вводом и выводом.
    
    ▶️ Она включает в себя следующие компоненты:
    1️⃣ std::cin: стандартный ввод (например, с клавиатуры)
    2️⃣ std::cout: стандартный вывод (например, на экран)
    3️⃣ std::cerr: стандартный вывод для сообщений об ошибках
    4️⃣ std::clog: стандартный вывод для сообщений журнала

    cin -> input()  // ввод информации
    cout -> print() // вывод информации
*/

#include <iostream>

using namespace std;

int main() {
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    std::cout << "Ваше число: " << number << std::endl;
    return 0;
}

// s = "sadasdsadbbrtbvfreferf"
// print(s)

/* Функиция №1
#include <iostream>

using namespace std;

int main() {
    string s;
    std::cout << "Введите число: ";
    std::cin >> s;
    std::cout << "Ваше число: " << s << std::endl;
    return 0;
}
*/

/* Функиция №2
    #include <iostream>

    using namespace std;

    int main() {
        int number = 8;
        std::cout << "Число по умолчанию: " << number << std::endl;
        std::cout << "Введите число: ";
        std::cin >> number;
        std::cout << "Число, которое ввёл пользователь: " << number << std::endl;
        return 0;
    }
*/
