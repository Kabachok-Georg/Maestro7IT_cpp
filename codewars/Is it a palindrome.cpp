/*
    [ Is it a palindrome ? ]

    Write a function that checks if a given string (case insensitive) is a palindrome.

    A palindrome is a word, number, phrase, or other sequence of symbols that reads the same backwards as forwards, such as madam or racecar.
*/

#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrom(const std::string& str) {
    std::string cleanedStr;
    std::transform(str.begin(), str.end(), std::back_inserter(cleanedStr), [](unsigned char c) {
        return std::tolower(c);
    });

    std::string reversedStr = cleanedStr;
    std::reverse(reversedStr.begin(), reversedStr.end());

    return cleanedStr == reversedStr;
}

/*
    1) cctype — это заголовочный файл в C++, который содержит функции для классификации и преобразования символов.
    Эти функции работают с символами типа char и могут использоваться для проверки, является ли символ цифрой, буквой, пробелом и т.д., а также для преобразования символов в верхний или нижний регистр.
    
    2) Ключевое слово const в C++ используется для обозначения того, что значение переменной или параметра не может быть изменено после его инициализации.
    
    3) ptr — это сокращение от слова "pointer" (указатель) в C++.
    Указатель — это переменная, которая хранит адрес другой переменной.
    Указатели широко используются в C++ для работы с динамической памятью, массивами и функциями.
*/



// Авторы: Дуплей Максим и Данилов Георгий
// Дата: 22.12.2024