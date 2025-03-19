#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/**
 * Техническое задание:
 *
 * Написать программу на C++, которая выполняет следующие действия:
 * 1. Читает текст стихотворения из файла "input.txt".
 * 2. Сортирует строки текста в алфавитном порядке.
 * 3. Записывает отсортированные строки в новый файл "output.txt".
 *
 * Требования:
 * - Программа должна корректно обрабатывать файлы с кодировкой UTF-8.
 * - В случае ошибки чтения или записи файла, программа должна выводить сообщение об ошибке.
 * - Программа должна быть написана с использованием стандартных библиотек C++.
 */

int main()
{
    // Открываем файл для чтения
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Ошибка открытия файла input.txt" << std::endl;
        return 1;
    }

    // Читаем строки из файла в вектор
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line))
    {
        lines.push_back(line);
    }
    inputFile.close();

    // Сортируем строки в алфавитном порядке
    std::sort(lines.begin(), lines.end());

    // Открываем файл для записи
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open())
    {
        std::cerr << "Ошибка открытия файла output.txt" << std::endl;
        return 1;
    }

    // Записываем отсортированные строки в файл
    for (const auto &sortedLine : lines)
    {
        outputFile << sortedLine << std::endl;
    }
    outputFile.close();

    std::cout << "Строки успешно отсортированы и записаны в файл output.txt" << std::endl;
    return 0;
}
