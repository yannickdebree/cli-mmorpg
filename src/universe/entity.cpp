#include <core/console.h>
#include <universe/entity.h>
#include <sstream>
#include <iostream>

Entity::Entity(int moving)
{
    Entity::moving = moving;
}

int Entity::getX()
{
    return Entity::x;
}

void Entity::setX(int x)
{
    Entity::x = x;
}

int Entity::getY()
{
    return Entity::y;
}

void Entity::setY(int y)
{
    Entity::y = y;
}

int Entity::getMoving()
{
    return Entity::moving;
}

void Entity::stats()
{
    Console::log("Position :");

    std::ostringstream x;
    x << Entity::getX();

    Console::log("    x : " + x.str());

    std::ostringstream y;
    y << Entity::getY();

    Console::log("    y : " + y.str());

    std::ostringstream moving;
    moving << Entity::getMoving();

    Console::log("Moving (time in milliseconds the creature spent to move to a near position): " + moving.str());
}