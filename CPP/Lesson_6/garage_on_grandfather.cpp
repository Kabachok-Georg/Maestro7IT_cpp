/*
    [ Гараж у деда ]

    Создать структуру гаража с автомобилями.
    Несколько автомобилей (3 штуки).
    Характеристики автомобиля - цвет, марка, год выпуска, двигатель.
*/

#include <iostream>
#include <string>

using namespace std;

struct Garaje {
  std::string colour;
  std::string mark_of_auto;
  int year_of_issue;
  std::string engine;
};

int main() {
    Garaje cool_ded;

  std::cout << "Введите цвет автомобиля деда: ";
  std::cin >> cool_ded.colour;
  
  std::cout << "Введите марку автомобиля деда: ";
  std::cin >> cool_ded.mark_of_auto;

  std::cout << "Введите год выпуска автомобиля деда: ";
  std::cin >> cool_ded.year_of_issue;

  std::cout << "Введите тип двигателя автомобиля деда (ДВС или Электический): ";
  std::cin >> cool_ded.engine;

  std::cout << ":Цвет автомобиля деда: " << cool_ded.colour << std::endl;
  std::cout << "Марка автомобиля деда: " << cool_ded.mark_of_auto << std::endl;
  std::cout << "Год выпуска автомобиля деда: " << cool_ded.year_of_issue << std::endl;
  std::cout << "Тип двигателя автомобиля деда: " << cool_ded.engine << std::endl;
  return 0;
}

/*
Более сложное решение + модуль рандом
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); 

    int poor_n = std::rand() % (500000 - 50000 + 1) + 50000;
    int rich_n = std::rand() % (200000 - 10000 + 1) + 10000;
    int year = std::rand() % (100000 - 50000 + 1) + 50000;
    int type = std::rand() % (10000 - 1000 + 1) + 1000;

    std::string c, m, t;
    int y, s = 0;

    std::cout << "Введите цвет авто: ";
    std::getline(std::cin, c);
    std::cout << "Введите марку авто: ";
    std::getline(std::cin, m);
    std::cout << "Введите год выпуска: ";
    std::cin >> y;
    std::cin.ignore(); // Игнорируем оставшийся символ новой строки
    std::cout << "Введите тип двигателя авто: ";
    std::getline(std::cin, t);

    if (m == "Mercedes-Benz" || m == "BMW" || m == "Audi" || m == "Lexus" ||
        m == "Porsche" || m == "Jaguar" || m == "Land Rover" || m == "Maserati" || m == "Bentley") {
        s += rich_n;
    } else {
        s += poor_n;
    }

    s += year;
    s += type;

    std::cout << "Цвет авто: " << c << ", Марка авто: " << m << ", Год выпуска: " << y
              << ", Тип двигателя авто: " << t << ", Общая цена: " << s << "$" << std::endl;

    return 0;
}
*/