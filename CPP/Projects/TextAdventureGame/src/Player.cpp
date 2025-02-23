#include "Player.h"

Player::Player() : health(100) {}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

void Player::heal(int amount) {
    health += amount;
    if (health > 100) health = 100;
}

void Player::addItem(const std::string& item) {
    inventory.push_back(item);
}

bool Player::removeItem(const std::string& item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        inventory.erase(it);
        return true;
    }
    return false;
}

void Player::addQuest(const std::string& quest) {
    quests.push_back(quest);
}

bool Player::completeQuest(const std::string& quest) {
    auto it = std::find(quests.begin(), quests.end(), quest);
    if (it != quests.end()) {
        quests.erase(it);
        return true;
    }
    return false;
}

int Player::getHealth() const {
    return health;
}

std::vector<std::string> Player::getInventory() const {
    return inventory;
}

std::vector<std::string> Player::getQuests() const {
    return quests;
}