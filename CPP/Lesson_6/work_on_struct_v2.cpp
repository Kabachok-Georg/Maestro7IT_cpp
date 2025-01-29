#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Person {
    std::string name;
    std::string surname;
    std::string patronymic;
    int age;
    double height;
};

// Функция для безопасного ввода строкового значения
std::string inputString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) {
            break;
        }
        std::cout << "Ошибка: ввод не может быть пустым. Повторите попытку.\n";
    }
    return input;
}

// Функция для безопасного ввода числового значения (целое число)
int inputInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value <= 0) {
            std::cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите положительное целое число.\n";
        } else {
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return value;
}

// Функция для безопасного ввода числового значения (с плавающей точкой)
double inputDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value <= 0) {
            std::cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите положительное число.\n";
        } else {
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return value;
}

// Функция для ввода данных о человеке
Person inputPerson() {
    Person person;
    person.name = inputString("Введите имя: ");
    person.surname = inputString("Введите фамилию: ");
    person.patronymic = inputString("Введите отчество: ");
    person.age = inputInt("Введите возраст: ");
    person.height = inputDouble("Введите рост (в метрах): ");
    return person;
}

// Функция для вывода данных о человеке
void printPerson(const Person& person) {
    std::cout << "\nИнформация о человеке:\n";
    std::cout << "ФИО: " << person.name << " " << person.surname << " " << person.patronymic << std::endl;
    std::cout << "Возраст: " << person.age << " лет" << std::endl;
    std::cout << "Рост: " << person.height << " м" << std::endl;
}

int main() {
    char choice;
    do {
        Person person1 = inputPerson();
        printPerson(person1);

        std::cout << "\nХотите ввести данные о другом человеке? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Программа завершена. Спасибо!\n";
    return 0;
}
