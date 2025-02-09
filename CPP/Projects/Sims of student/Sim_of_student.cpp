#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
#include <windows.h> // Для функций SetConsoleCP и SetConsoleOutputCP

class Student {
public:
    double money;
    int satiety;
    int sleep;
    int mood;
    int study_progress;
    int days_left;
    int health; // Новый параметр здоровье

    Student() {
        money = 4000;
        satiety = 100;
        sleep = 100;
        mood = 100;
        study_progress = 50;
        days_left = 365;
        health = 100; // Начальное значение здоровья
    }

    void showStatus() {
        std::cout << "\nСтатус студента:" << std::endl;
        std::cout << "Деньги: " << money << " руб" << std::endl;
        std::cout << "Сытость: " << satiety << "%" << std::endl;
        std::cout << "Сон: " << sleep << "%" << std::endl;
        std::cout << "Настроение: " << mood << "%" << std::endl;
        std::cout << "Успеваемость: " << study_progress << "%" << std::endl;
        std::cout << "Здоровье: " << health << "%" << std::endl;
        std::cout << "Дней до конца курса: " << days_left << "\n" << std::endl;
    }

    void study() {
        std::cout << "Вы занимаетесь учебой..." << std::endl;
        study_progress += 10;
        mood -= 10;
        sleep -= 10;
        satiety -= 5;
        health -= 5; // Учеба ухудшает здоровье
    }

    void work() {
        std::cout << "Вы пошли работать..." << std::endl;
        money += 500;
        mood -= 10;
        sleep -= 15;
        satiety -= 10;
        health -= 5; // Работа ухудшает здоровье
    }

    void eat() {
        std::cout << "Вы поели..." << std::endl;
        money -= 200;
        satiety = 100;
        health += 5; // Еда улучшает здоровье
    }

    void sleepAction() {
        std::cout << "Вы поспали..." << std::endl;
        sleep = 100;
        mood += 10;
        health += 10; // Сон улучшает здоровье
    }

    void relax() {
        std::cout << "Вы отдыхаете..." << std::endl;
        mood = 100;
        sleep += 10;
        satiety -= 5;
        health += 5; // Отдых улучшает здоровье
    }

    void visitDoctor() {
        std::cout << "Вы посетили врача..." << std::endl;
        money -= 300;
        health = 100; // Врач полностью восстанавливает здоровье
    }

    bool isAlive() {
        return (satiety > 0 && sleep > 0 && study_progress > 0 && health > 0);
    }

    void updateStatus() {
        if (satiety < 50) {
            mood -= 5;
            study_progress -= 2;
            health -= 5; // Низкая сытость ухудшает здоровье
        }
        if (sleep < 50) {
            mood -= 5;
            study_progress -= 2;
            health -= 5; // Низкий сон ухудшает здоровье
        }
        if (health < 50) {
            mood -= 5;
            study_progress -= 2; // Низкое здоровье ухудшает настроение и успеваемость
        }
    }
};

void randomEvent(Student &player) {
    int event = rand() % 6;
    switch (event) {
        case 0:
            std::cout << "Вы заболели [Потеряли 20% здоровья]" << std::endl;
            player.health -= 20;
            break;
        case 1:
            std::cout << "Вы получили стипендию [+300 руб]" << std::endl;
            player.money += 300;
            break;
        case 2:
            std::cout << "Вы потеряли кошелек [-200 руб]" << std::endl;
            player.money -= 200;
            break;
        case 3:
            std::cout << "Вы нашли деньги на улице [+100 руб]" << std::endl;
            player.money += 100;
            break;
        case 4:
            std::cout << "Вы простудились [Потеряли 10% настроения]" << std::endl;
            player.mood -= 10;
            break;
        case 5:
            std::cout << "Вы попали под дождь и промокли [Потеряли 10% здоровья]" << std::endl;
            player.health -= 10;
            break;
    }
}

void setDifficulty(Student &player, int difficulty) {
    switch (difficulty) {
        case 1:
            player.money = 5000;
            player.satiety = 120;
            player.sleep = 120;
            player.mood = 120;
            player.health = 120;
            break;
        case 2:
            player.money = 3000;
            player.satiety = 100;
            player.sleep = 100;
            player.mood = 100;
            player.health = 100;
            break;
        case 3:
            player.money = 2000;
            player.satiety = 80;
            player.sleep = 80;
            player.mood = 80;
            player.health = 80;
            break;
        default:
            std::cout << "Неверный выбор уровня сложности. Установлен средний уровень." << std::endl;
            player.money = 3000;
            player.satiety = 100;
            player.sleep = 100;
            player.mood = 100;
            player.health = 100;
            break;
    }
}

void saveGame(const Student &player, const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << player.money << " " << player.satiety << " " << player.sleep << " " << player.mood << " " << player.study_progress << " " << player.days_left << " " << player.health;
        file.close();
        std::cout << "Игра сохранена успешно!" << std::endl;
    } else {
        std::cout << "Ошибка при сохранении игры." << std::endl;
    }
}

void loadGame(Student &player, const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> player.money >> player.satiety >> player.sleep >> player.mood >> player.study_progress >> player.days_left >> player.health;
        file.close();
        std::cout << "Игра загружена успешно!" << std::endl;
    } else {
        std::cout << "Ошибка при загрузке игры. Файл не найден." << std::endl;
    }
}

void playGame() {
    SetConsoleOutputCP(CP_UTF8); // Устанавливаем кодовую страницу для вывода на консоль на UTF-8

    srand(static_cast<unsigned int>(time(0))); // Исправлено предупреждение
    Student player;
    std::cout << "Добро пожаловать в Симулятор Студента" << std::endl;

    int difficulty;
    std::cout << "Выберите уровень сложности (1 - легкий, 2 - средний, 3 - тяжелый): ";
    while (!(std::cin >> difficulty) || (difficulty < 1 || difficulty > 3)) {
        std::cout << "Неверный выбор. Пожалуйста, введите число от 1 до 3: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setDifficulty(player, difficulty);

    char loadChoice;
    std::cout << "Хотите загрузить сохраненную игру? (y/n): ";
    std::cin >> loadChoice;
    if (loadChoice == 'y' || loadChoice == 'Y') {
        std::string filename;
        std::cout << "Введите имя файла для загрузки: ";
        std::cin >> filename;
        loadGame(player, filename);
    }

    while (player.days_left > 0 && player.isAlive()) {
        std::cout << "\nДень " << (366 - player.days_left) << ":" << std::endl;
        for (int i = 0; i < 2; i++) { // Два действия в день
            player.showStatus();
            std::cout << "Выберите действие:\n1 - Учеба\n2 - Работа\n3 - Покушать\n4 - Поспать\n5 - Отдыхать\n6 - Посетить врача\n7 - Сохранить игру\nВаш выбор: ";
            int choice;
            while (!(std::cin >> choice) || (choice < 1 || choice > 7)) {
                std::cout << "Неверный выбор. Пожалуйста, введите число от 1 до 7: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            switch (choice) {
                case 1: player.study(); break;
                case 2: player.work(); break;
                case 3: player.eat(); break;
                case 4: player.sleepAction(); break;
                case 5: player.relax(); break;
                case 6: player.visitDoctor(); break;
                case 7: {
                    std::string filename;
                    std::cout << "Введите имя файла для сохранения: ";
                    std::cin >> filename;
                    saveGame(player, filename);
                    i--; // Не считать это действие
                    break;
                }
                default: std::cout << "Неверный выбор!" << std::endl;
            }

            player.updateStatus();
            randomEvent(player);

            if (!player.isAlive()) {
                std::cout << "Вы не смогли продолжить обучение. Игра окончена." << std::endl;
                return;
            }
        }
        player.days_left--;
    }

    if (player.study_progress >= 100) {
        std::cout << "Поздравляем. Вы успешно завершили обучение!" << std::endl;
    } else {
        std::cout << "К сожалению, вы не смогли завершить учебу. Попробуйте еще раз!" << std::endl;
    }
}

int main() {
    while (true) {
        playGame();

        char playAgain;
        std::cout << "Хотите начать новую игру? (y/n): ";
        std::cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }

    return 0;
}
