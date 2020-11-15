#include <universe/world.h>
#include <universe/entity.h>
#include <user/move.h>

Move::Move(World *world, Entity *entity, int destinationX, int destinationY)
{
    Move::destinationX = destinationX;
    Move::destinationY = destinationY;
    Move::world = world;
    Move::entity = entity;
}

Move::~Move()
{
    delete Move::world;
    delete Move::entity;
}

void Move::start()
{
    Move::world->moveEntity(Move::entity, Move::destinationX, Move::destinationY);
}