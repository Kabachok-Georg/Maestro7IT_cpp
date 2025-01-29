#include <iostream>
#include <string>

using namespace std;

struct Person {
  std::string name;
  std::string surname;
  std::string patronymic; // исправлено на "patronymic"
  int age;
  double height;
};

int main() {
  Person person1;

  std::cout << "Введите фамилию: ";
  std::cin >> person1.surname;

  std::cout << "Введите имя: ";
  std::cin >> person1.name;

  std::cout << "Введите отчество: ";
  std::cin >> person1.patronymic;

  std::cout << "Введите возраст: ";
  std::cin >> person1.age;

  std::cout << "Введите рост (в метрах): ";
  std::cin >> person1.height;

  std::cout << "\nФИО: " << person1.name << " " << person1.surname << " "
            << person1.patronymic << std::endl;
  std::cout << "Возраст: " << person1.age << std::endl;
  std::cout << "Рост: " << person1.height << " м" << std::endl;

  return 0;
}
