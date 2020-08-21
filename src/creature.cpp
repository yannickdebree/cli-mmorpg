#include <console.h>
#include <creature.h>
#include <iostream>
#include <sstream>

Creature::Creature(int maxLp, int maxMp, int moving)
{
    Creature::level = 0;
    Creature::xp = 0;
    Creature::maxXp = 100;
    Creature::lp = maxLp;
    Creature::maxLp = maxLp;
    Creature::mp = maxMp;
    Creature::maxMp = maxMp;
    Creature::moving = moving;
}

int Creature::getX()
{
    return Creature::x;
}

void Creature::setX(int x)
{
    Creature::x = x;
}

int Creature::getY()
{
    return Creature::y;
}

void Creature::setY(int y)
{
    Creature::y = y;
}

int Creature::getLevel()
{
    return Creature::level;
}

int Creature::getXp()
{
    return Creature::xp;
}

int Creature::getMapXp()
{
    return Creature::maxXp;
}

int Creature::getLp()
{
    return Creature::lp;
}

int Creature::getMaxLp()
{
    return Creature::maxLp;
}

int Creature::getMp()
{
    return Creature::mp;
}

int Creature::getMaxMp()
{
    return Creature::maxMp;
}

int Creature::getMooving()
{
    return Creature::moving;
}

void Creature::showStats()
{
    std::ostringstream lp;
    lp << Creature::getLp();

    std::ostringstream maxLp;
    maxLp << Creature::getMaxLp();

    printLine("LP : " + lp.str() + "/" + maxLp.str());

    std::ostringstream mp;
    mp << Creature::getMp();

    std::ostringstream maxMp;
    maxMp << Creature::getMaxMp();

    printLine("MP : " + mp.str() + "/" + maxMp.str());

    std::ostringstream xp;
    xp << Creature::getXp();

    std::ostringstream maxXp;
    maxXp << Creature::getMapXp();

    printLine("XP : " + xp.str() + "/" + maxXp.str());

    std::ostringstream x;
    x << Creature::getX();

    std::ostringstream y;
    y << Creature::getY();

    printLine("Position :");
    printLine("    x : " + x.str());
    printLine("    y : " + y.str());
}