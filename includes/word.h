#ifndef WORLD_H
#define WORLD_H

#include <creature.h>
#include <iostream>
#include <vector>

class World
{
private:
    int maxX;
    int maxY;
    std::string name;
    std::vector<Creature *> creatures;

public:
    World(std::string name, int maxX, int maxY);
    ~World();
    int getMaxX();
    int getMaxY();
    std::string getName();
    void placeCreature(Creature *creature, int x, int y);
    void moveCreature(Creature *creature, int x, int y);
};

#endif