#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <map>
#include <vector>

class Location {
public:
    Location(const std::string& name, const std::string& description);
    void addPath(const std::string& direction, Location* location);
    void addItem(const std::string& item);
    void addEnemy(const std::string& enemy);
    void addNPC(const std::string& npc);
    void setLock(const std::string& keyItem);
    Location* move(const std::string& direction);
    bool takeItem(const std::string& item);
    bool unlock(const std::string& item);

    std::string getName() const;
    std::string getDescription() const;
    std::vector<std::string> getItems() const;
    std::vector<std::string> getEnemies() const;
    std::vector<std::string> getNPCs() const;
    bool isLocked() const;

private:
    std::string name;
    std::string description;
    std::map<std::string, Location*> paths;
    std::vector<std::string> items;
    std::vector<std::string> enemies;
    std::vector<std::string> npcs;
    bool locked;
    std::string keyItem;
};

#endif // LOCATION_H