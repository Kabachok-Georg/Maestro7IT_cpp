/*
    📖 ostream — это класс для вывода данных.
    ▶️ Он является частью библиотеки iostream и используется для вывода данных на стандартные и нестандартные потоки (например, в файлы).
*/

#include <iostream>

using namespace std;

int main() {
    std::ostream &out = std::cout; // Использование std::cout через ссылку на ostream
    out << "Hello, ostream" << std::endl;
    return 0;
}

// ostream также предоставляет операции перегрузки для различных типов данных, что делает его очень гибким инструментом для вывода информации.
