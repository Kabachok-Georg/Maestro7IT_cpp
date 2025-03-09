#include <iostream>
#include <random>
#include <string>
#include <algorithm> // Добавьте этот заголовочный файл

std::string generatePassword(int length)
{
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
    std::string password;

    // Используем <random> для генерации случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, characters.size() - 1);

    // Гарантируем наличие хотя бы одного символа каждого типа
    std::string guaranteedChars = "aA1!"; // Минимальный набор: строчная, заглавная, цифра, спецсимвол

    for (char ch : guaranteedChars)
    {
        password += ch;
    }

    // Заполняем оставшуюся длину пароля
    for (int i = guaranteedChars.size(); i < length; ++i)
    {
        password += characters[dis(gen)];
    }

    // Перемешиваем пароль для случайности
    std::shuffle(password.begin(), password.end(), gen);

    return password;
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int length;
    std::cout << "Введите длину пароля (минимум 4): ";
    while (!(std::cin >> length) || length < 4)
    {
        std::cout << "Некорректная длина. Пожалуйста, введите число больше или равное 4: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::string password = generatePassword(length);
    std::cout << "Сгенерированный пароль: " << password << std::endl;

    return 0;
}
