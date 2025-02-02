/*
    Домашнее задание:
    Написать программу на С++ для ведения личного учёта денежных средств.

    Счёт: 10 000 рублей
    Поход в магазин = -500 рублей
    Выполнение фриланс заказа = +750 рублей

    29.01.2025 Счёт: 10 250 рублей
*/

#include <iostream>
#include <string>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time()

class Income {
public:
    int salary;
    int part_time;
    int lucky;
};

class Expenses {
public:
    int taxes_and_home;
    int food;
    int environment; // Исправлено написание на "environment"
    int unlucky;
};

int main() {
    Income money;
    Expenses costs;

    int check = 10000; // Начальный счет
    money.salary = 50000; // Зарплата

    std::cout << "Cчёт: " << check << std::endl;
    check += money.salary; // Добавляем зарплату
    std::cout << "Зарплата: +" << money.salary << " рублей" << std::endl;
    std::cout << "Cчёт: " << check << std::endl;

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    money.part_time = 0; // Начальное значение переменной part_time
    money.lucky = 0;

    // Генерируем случайное число от 0 до 19 для подработки
    int randomValue_parttime = rand() % 20;
    // Генерируем случайное число от 0 до 6 для удачи
    int randomValue_1 = rand() % 7;

    // Проверка на подработку
    if (randomValue_parttime == 0) {
        money.part_time = 1000; // Подработка
        std::cout << "От подработки вы заработали: +" << money.part_time << " рублей" << std::endl;
        check += money.part_time; // Обновляем счет
        std::cout << "Cчёт: " << check << std::endl;
    }

    // Проверка на удачу
    if (randomValue_1 == 0) {
        money.lucky = 500; // Удача
        std::cout << "Чудом на земле вы нашли: +" << money.lucky << " рублей" << std::endl;
        check += money.lucky; // Обновляем счет
        std::cout << "Cчёт: " << check << std::endl;
    }

    // Устанавливаем фиксированные расходы
    costs.taxes_and_home = 3000; // Налоги и жилье
    costs.food = 2000;            // Продукты питания
    costs.environment = 500;      // Экологические расходы
    costs.unlucky = 1500;         // Непредвиденные расходы

    // Вычитаем расходы из общего счета
    check -= (costs.taxes_and_home + costs.food + costs.environment + costs.unlucky);
    
    std::cout << "Расходы:" << std::endl;
    std::cout << "Налоги и жилье: -" << costs.taxes_and_home << " рублей" << std::endl;
    std::cout << "Продукты питания: -" << costs.food << " рублей" << std::endl;
    std::cout << "Развлекательные расходы: -" << costs.environment << " рублей" << std::endl;
    std::cout << "Непредвиденные расходы: -" << costs.unlucky << " рублей" << std::endl;
    
    std::cout << "Cчёт после расходов: " << check << " рублей" << std::endl;

    return 0;
}
