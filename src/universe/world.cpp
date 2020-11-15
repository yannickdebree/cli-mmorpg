#include <core/console.h>
#include <universe/world.h>
#include <sstream>
#include <unistd.h>
#include <stdexcept>

World::World(std::string name, int maxX, int maxY)
{
    World::maxX = maxX;
    World::maxY = maxY;
    World::name = name;
}

World::~World()
{
    int entitiesNbr = World::entities.size();
    for (int i = 0; i < entitiesNbr; ++i)
    {
        delete entities[i];
    }
}

void World::placeEntity(Entity *entity, int x, int y)
{
    std::ostringstream ostr;
    if (x < 0 || x > World::maxX)
    {
        ostr << World::maxX;
        throw std::runtime_error("Entity::x must be between 0 and " + ostr.str() + ".");
    }
    if (y < 0 || x > World::maxY)
    {
        ostr << World::maxY;
        throw std::runtime_error("Entity::y must be between 0 and " + ostr.str() + ".");
    }

    World::entities.push_back(entity);

    entity->setX(x);
    entity->setY(y);
}

void World::moveEntity(Entity *entity, int destinationX, int destinationY)
{
    std::ostringstream xOstr;
    if (destinationX < 0 || destinationX > World::maxX)
    {
        xOstr << World::maxX;
        throw std::runtime_error("Entity::x must be between 0 and " + xOstr.str() + ".");
    }
    xOstr << destinationY;

    std::ostringstream yOstr;
    if (destinationY < 0 || destinationY > World::maxX)
    {
        yOstr << World::maxX;
        throw std::runtime_error("Entity::x must be between 0 and " + yOstr.str() + ".");
    }
    yOstr << destinationY;

    int xDirection = destinationX - entity->getX();
    int yDirection = destinationY - entity->getY();

    Console::log("Moved in progress...");

    for (int i = 0; i < abs(xDirection); ++i)
    {
        for (int j = 0; j < abs(yDirection); ++j)
        {
            usleep(entity->getMoving() * 1000);
            entity->setX(entity->getX() + (xDirection > 0 ? 1 : -1));
            entity->setY(entity->getY() + (yDirection > 0 ? 1 : -1));
        }
    }

    Console::log("Moved to " + xOstr.str() + "." + yOstr.str() + "!");
}