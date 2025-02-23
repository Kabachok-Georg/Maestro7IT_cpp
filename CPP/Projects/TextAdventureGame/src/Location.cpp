#include "Location.h"

Location::Location(const std::string& name, const std::string& description)
    : name(name), description(description), locked(false) {}

void Location::addPath(const std::string& direction, Location* location) {
    paths[direction] = location;
}

void Location::addItem(const std::string& item) {
    items.push_back(item);
}

void Location::addEnemy(const std::string& enemy) {
    enemies.push_back(enemy);
}

void Location::addNPC(const std::string& npc) {
    npcs.push_back(npc);
}

void Location::setLock(const std::string& keyItem) {
    locked = true;
    this->keyItem = keyItem;
}

Location* Location::move(const std::string& direction) {
    if (paths.find(direction) != paths.end()) {
        return paths[direction];
    }
    return nullptr;
}

bool Location::takeItem(const std::string& item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
        return true;
    }
    return false;
}

bool Location::unlock(const std::string& item) {
    if (locked && item == keyItem) {
        locked = false;
        return true;
    }
    return false;
}

std::string Location::getName() const {
    return name;
}

std::string Location::getDescription() const {
    return description;
}

std::vector<std::string> Location::getItems() const {
    return items;
}

std::vector<std::string> Location::getEnemies() const {
    return enemies;
}

std::vector<std::string> Location::getNPCs() const {
    return npcs;
}

bool Location::isLocked() const {
    return locked;
}