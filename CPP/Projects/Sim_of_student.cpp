#include <iostream>
#include <string>


class Statistic{
public:

    double money;
    int hp;
    int satiety;
    int dream;
    int mood;
    int ac_per;

};
int main(){
    Statistic check;
    char str[] = "\nДобро пожаловать в Симулятор Студента!\nЗдесь твоя главная задача:\n*Здать все экзамены и пройти на следующий курс\n*Стараться не двинуть коней со скуки\n*Высыпаться\n*Не умереть от голода\n \nПОДСКАЗКА\nВ днь даётся всего два действия\nДля их выбора вводите цифры: 1, 2, 3, 4, 5";

    std::cout << str << std::endl;
int year = 365;
int month = 30;
check.money=4000;

std::cout<<"Дней до конца курса: "<<year<<std::endl;
std::cout<<"Дней до получения стипендии: "<<year<<std::endl;
std::cout<<"Денег на счету: "<<check.money<<std::endl;
std::cout<<"Что вы будете делать сегодня?"<<std::endl;











}
