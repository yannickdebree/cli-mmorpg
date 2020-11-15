#ifndef PLAYER_H
#define PLAYER_H

#include <universe/creature.h>
#include <vector>
#include <iostream>

class Player
{
private:
    int creaturesNbrMax = 10;
    std::vector<Creature *> creatures;
    std::string pseudo;

public:
    Player(std::string pseudo);
    ~Player();
    void addCreature(Creature *value);
    std::string getPseudo();
};

#endif