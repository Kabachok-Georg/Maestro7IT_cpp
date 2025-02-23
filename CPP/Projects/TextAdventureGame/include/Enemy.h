#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int health);
    void takeDamage(int damage);
    bool isAlive() const;
    std::string getName() const;
    int getHealth() const;

private:
    std::string name;
    int health;
};

#endif // ENEMY_H