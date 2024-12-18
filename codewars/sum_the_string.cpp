/*
    [ Sum The Strings ]

    Create a function that takes 2 integers in form of a string as an input, and outputs the sum (also as a string):

    Example: (Input1, Input2 -->Output)

    "4",  "5" --> "9"
    "34", "5" --> "39"
    "", "" --> "0"
    "2", "" --> "2"
    "-5", "3" --> "-2"
    Notes:

    If either input is an empty string, consider it as zero.

    Inputs and the expected output will never exceed the signed 32-bit integer limit (2^31 - 1)
*/


#include <string>

std::string sum_str(const std::string& a, const std::string& b) {
    int num1 = a.empty() ? 0 : std::stoi(a); // Если строка пустая, считать ее как 0
    int num2 = b.empty() ? 0 : std::stoi(b); // Если строка пустая, считать ее как 0
    int sum = num1 + num2; // Сложить числа
    return std::to_string(sum); // Преобразовать результат обратно в строку
}

/*
#include <string>

std::string sum_str(const std::string& a, const std::string& b) {
  return std::to_string(std::stoi(a == "" ? "0" : a) + std::stoi(b == "" ? "0" : b));
}
*/

// Авторы: Дуплей Максим и Данилов Георгий
// Дата: 18.12.2024