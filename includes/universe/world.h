#ifndef WORLD_H
#define WORLD_H

#include <universe/entity.h>
#include <iostream>
#include <vector>

class World
{
private:
    int maxX;
    int maxY;
    std::string name;
    std::vector<Entity *> entities;

public:
    World(std::string name, int maxX, int maxY);
    ~World();
    int getMaxX();
    int getMaxY();
    std::string getName();
    void placeEntity(Entity *entity, int x, int y);
    void moveEntity(Entity *entity, int destinationX, int destinationY);
};

#endif