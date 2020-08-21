#include <console.h>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <word.h>

World::World(std::string name, int maxX, int maxY)
{
    World::maxX = maxX;
    World::maxY = maxY;
    World::name = name;
}

World::~World()
{
    int creaturesNbr = World::creatures.size();
    for (int i = 0; i < creaturesNbr; ++i)
    {
        delete creatures[i];
    }
}

void World::placeCreature(Creature *creature, int x, int y)
{
    std::ostringstream ostr;
    if (x < 0 || x > World::maxX)
    {
        ostr << World::maxX;
        printLine("Creature::x must be between 0 and " + ostr.str() + ".");
        exit(0);
    }
    if (y < 0 || x > World::maxY)
    {
        ostr << World::maxY;
        printLine("Creature::y must be between 0 and " + ostr.str() + ".");
        exit(0);
    }

    World::creatures.push_back(creature);

    creature->setX(x);
    creature->setY(y);
}

void World::moveCreature(Creature *creature, int x, int y)
{
    std::ostringstream xOstr;
    if (x < 0 || x > World::maxX)
    {
        xOstr << World::maxX;
        printLine("Creature::x must be between 0 and " + xOstr.str() + ".");
        exit(0);
    }
    xOstr << x;

    std::ostringstream yOstr;
    if (y < 0 || y > World::maxX)
    {
        yOstr << World::maxX;
        printLine("Creature::x must be between 0 and " + yOstr.str() + ".");
        exit(0);
    }
    yOstr << y;

    int xDirection = x - creature->getX();
    int yDirection = y - creature->getY();

    printLine("Moved in progress...");

    for (int i = 0; i < xDirection; ++i)
    {
        for (int j = 0; j < yDirection; ++j)
        {
            // TODO : calcul new direction
            usleep(creature->getMooving() * 1000);
            creature->setX(creature->getX() + 1);
            creature->setY(creature->getY() + 1);
        }
    }

    printLine("Moved to " + xOstr.str() + "." + yOstr.str() + "!");
}