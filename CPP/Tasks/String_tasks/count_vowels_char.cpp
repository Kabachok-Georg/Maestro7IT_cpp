#include <iostream>
#include <string>
#include <clocale>   // Для работы с setlocale
#include <windows.h> // Для SetConsoleOutputCP (только Windows)
#include <limits>    // Для numeric_limits

using namespace std;

// Константа с гласными для русского и английского языков
const string VOWELS = "aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";

void countLetters(const string &str, int &vowels, int &consonants)
{
    vowels = 0;
    consonants = 0;

    for (char ch : str)
    {
        if (VOWELS.find(ch) != string::npos)
        {
            vowels++;
        }
        else if (isalpha(ch))
        {
            consonants++;
        }
    }
}

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    // Настройка консоли Windows для UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    char choice = 'y';

    while (tolower(choice) == 'y')
    {
        string input;
        cout << "╔══════════════════════════════╗\n"
             << "║   Введите текст для анализа: ║\n"
             << "╚══════════════════════════════╝\n> ";

        getline(cin, input);

        int vowels, consonants;
        countLetters(input, vowels, consonants);

        cout << "\n════════ Результаты ═════════\n"
             << "• Гласные: " << vowels << "\n"
             << "• Согласные: " << consonants << "\n"
             << "═════════════════════════════\n\n"
             << "Продолжить? (y/n): ";

        cin >> choice;
        clearInputBuffer(); // Очистка буфера ввода
        cout << endl;
    }

    cout << "Программа завершена. Нажмите Enter...";
    clearInputBuffer();
    return 0;
}