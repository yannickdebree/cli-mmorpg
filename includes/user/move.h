#ifndef MOVE_H
#define MOVE_H

#include <universe/entity.h>
#include <universe/world.h>

class Move
{
private:
    int destinationX;
    int destinationY;
    World *world;
    Entity *entity;

public:
    Move(World *world, Entity *entity, int destinationX, int destinationY);
    ~Move();
    void start();
};

#endif