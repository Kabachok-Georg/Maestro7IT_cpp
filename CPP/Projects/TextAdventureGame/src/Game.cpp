#include "Game.h"
#include <iostream>
#include <fstream>
#include <json/json.h>

Game::Game() {
    // Инициализация игры
}

void Game::start() {
    // Основной игровой цикл
}

void Game::showInstructions() const {
    std::cout << "Тайна Затерянного Города\n==========================\n";
    // Вывод инструкций
}

void Game::showHelp() const {
    std::cout << "Список команд:\n";
    // Вывод списка команд
}

void Game::saveGame(const Player& player, const Location* currentLocation) const {
    Json::Value gameState;
    gameState["player"]["health"] = player.getHealth();
    for (const auto& item : player.getInventory()) {
        gameState["player"]["inventory"].append(item);
    }
    for (const auto& quest : player.getQuests()) {
        gameState["player"]["quests"].append(quest);
    }
    gameState["current_location"] = currentLocation->getName();

    std::ofstream saveFile("savegame.json");
    saveFile << gameState;
    saveFile.close();
    std::cout << "Игра сохранена.\n";
}

void Game::loadGame(Player& player, Location*& currentLocation) const {
    std::ifstream saveFile("savegame.json");
    if (!saveFile) {
        std::cout << "Сохранение не найдено.\n";
        return;
    }

    Json::Value gameState;
    saveFile >> gameState;
    saveFile.close();

    player = Player();
    player.takeDamage(100 - gameState["player"]["health"].asInt());
    for (const auto& item : gameState["player"]["inventory"]) {
        player.addItem(item.asString());
    }
    for (const auto& quest : gameState["player"]["quests"]) {
        player.addQuest(quest.asString());
    }

    std::string currentLocationName = gameState["current_location"].asString();
    // Найти локацию по имени и установить currentLocation
}

bool Game::fight(Player& player, Enemy& enemy) {
    // Логика боя
    return true;
}

void Game::randomEvent(Location* location) {
    // Логика случайного события
}

void Game::interactNPC(NPC& npc) {
    // Логика взаимодействия с NPC
}