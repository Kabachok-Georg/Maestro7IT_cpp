#include "Enemy.h"

Enemy::Enemy(const std::string& name, int health)
    : name(name), health(health) {}

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

bool Enemy::isAlive() const {
    return health > 0;
}

std::string Enemy::getName() const {
    return name;
}

int Enemy::getHealth() const {
    return health;
}