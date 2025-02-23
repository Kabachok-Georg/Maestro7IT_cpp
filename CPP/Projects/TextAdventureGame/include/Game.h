#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Location.h"

class Game {
public:
    Game();
    void start();
    void showInstructions() const;
    void showHelp() const;
    void saveGame(const Player& player, const Location* currentLocation) const;
    void loadGame(Player& player, Location*& currentLocation) const;
    bool fight(Player& player, Enemy& enemy);
    void randomEvent(Location* location);
    void interactNPC(NPC& npc);

private:
    Player player;
    Location* currentLocation;
};

#endif // GAME_H