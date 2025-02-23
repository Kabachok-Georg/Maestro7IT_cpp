#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
public:
    Player();
    void takeDamage(int damage);
    void heal(int amount);
    void addItem(const std::string& item);
    bool removeItem(const std::string& item);
    void addQuest(const std::string& quest);
    bool completeQuest(const std::string& quest);

    int getHealth() const;
    std::vector<std::string> getInventory() const;
    std::vector<std::string> getQuests() const;

private:
    int health;
    std::vector<std::string> inventory;
    std::vector<std::string> quests;
};

#endif // PLAYER_H