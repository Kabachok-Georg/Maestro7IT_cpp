/*
    Задача №1: Перевод температуры
    Описание: Напишите программу, которая переводит температуру из Цельсия в Фаренгейты, Кельвины, Реомюры и наоборот.
*/

#include <iostream>

void celsiusToFahrenheit(double celsius)
{
    double fahrenheit = (celsius * 9 / 5) + 32;
    std::cout << celsius << " градусов Цельсия = " << fahrenheit << " градусов Фаренгейта" << std::endl;
}

void fahrenheitToCelsius(double fahrenheit)
{
    double celsius = (fahrenheit - 32) * 5 / 9;
    std::cout << fahrenheit << " градусов Фаренгейта = " << celsius << " градусов Цельсия" << std::endl;
}

void celsiusToKelvin(double celsius)
{
    double kelvin = celsius + 273.15;
    std::cout << celsius << " градусов Цельсия = " << kelvin << " Кельвинов" << std::endl;
}

void kelvinToCelsius(double kelvin)
{
    double celsius = kelvin - 273.15;
    std::cout << kelvin << " Кельвинов = " << celsius << " градусов Цельсия" << std::endl;
}

void celsiusToReaumur(double celsius)
{
    double reaumur = celsius * 0.8;
    std::cout << celsius << " градусов Цельсия = " << reaumur << " градусов Реомюра" << std::endl;
}

void reaumurToCelsius(double reaumur)
{
    double celsius = reaumur * 1.25;
    std::cout << reaumur << " градусов Реомюра = " << celsius << " градусов Цельсия" << std::endl;
}

void kelvinToFahrenheit(double kelvin)
{
    double fahrenheit = (kelvin * 9 / 5) - 459.67;
    std::cout << kelvin << " Кельвинов = " << fahrenheit << " градусов Фаренгейта" << std::endl;
}

void fahrenheitToKelvin(double fahrenheit)
{
    double kelvin = (fahrenheit + 459.67) * 5 / 9;
    std::cout << fahrenheit << " градусов Фаренгейта = " << kelvin << " Кельвинов" << std::endl;
}

void reaumurToFahrenheit(double reaumur)
{
    double fahrenheit = reaumur * 2.25 + 32;
    std::cout << reaumur << " градусов Реомюра = " << fahrenheit << " градусов Фаренгейта" << std::endl;
}

void fahrenheitToReaumur(double fahrenheit)
{
    double reaumur = (fahrenheit - 32) * 4 / 9;
    std::cout << fahrenheit << " градусов Фаренгейта = " << reaumur << " градусов Реомюра" << std::endl;
}

int main()
{
    int choice;
    double temperature;

    std::cout << "Выберите направление перевода:" << std::endl;
    std::cout << "1. Цельсий в Фаренгейт" << std::endl;
    std::cout << "2. Фаренгейт в Цельсий" << std::endl;
    std::cout << "3. Цельсий в Кельвин" << std::endl;
    std::cout << "4. Кельвин в Цельсий" << std::endl;
    std::cout << "5. Цельсий в Реомюр" << std::endl;
    std::cout << "6. Реомюр в Цельсий" << std::endl;
    std::cout << "7. Кельвин в Фаренгейт" << std::endl;
    std::cout << "8. Фаренгейт в Кельвин" << std::endl;
    std::cout << "9. Реомюр в Фаренгейт" << std::endl;
    std::cout << "10. Фаренгейт в Реомюр" << std::endl;
    std::cin >> choice;

    std::cout << "Введите температуру: ";
    std::cin >> temperature;

    switch (choice)
    {
    case 1:
        celsiusToFahrenheit(temperature);
        break;
    case 2:
        fahrenheitToCelsius(temperature);
        break;
    case 3:
        celsiusToKelvin(temperature);
        break;
    case 4:
        kelvinToCelsius(temperature);
        break;
    case 5:
        celsiusToReaumur(temperature);
        break;
    case 6:
        reaumurToCelsius(temperature);
        break;
    case 7:
        kelvinToFahrenheit(temperature);
        break;
    case 8:
        fahrenheitToKelvin(temperature);
        break;
    case 9:
        reaumurToFahrenheit(temperature);
        break;
    case 10:
        fahrenheitToReaumur(temperature);
        break;
    default:
        std::cout << "Неверный выбор!" << std::endl;
    }

    return 0;
}
