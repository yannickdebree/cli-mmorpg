#include <core/console.h>
#include <universe/creature.h>
#include <universe/entity.h>
#include <sstream>
#include <iostream>

Creature::Creature(int maxLp, int maxMp, int moving) : Entity(moving)
{
    Creature::lp = maxLp;
    Creature::maxLp = maxLp;
    Creature::mp = maxMp;
    Creature::maxMp = maxMp;
    Creature::level = 0;
    Creature::xp = 0;
    Creature::maxXp = 100;
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

int Creature::getLevel()
{
    return Creature::level;
}

int Creature::getXp()
{
    return Creature::xp;
}

int Creature::getMaxXp()
{
    return Creature::maxXp;
}

void Creature::stats()
{
    std::ostringstream lp;
    lp << Creature::getLp();

    std::ostringstream maxLp;
    maxLp << Creature::getMaxLp();

    Console::log("LP : " + lp.str() + "/" + maxLp.str());

    std::ostringstream mp;
    mp << Creature::getMp();

    std::ostringstream maxMp;
    maxMp << Creature::getMaxMp();

    Console::log("MP : " + mp.str() + "/" + maxMp.str());

    std::ostringstream level;
    level << Creature::getLevel();

    Console::log("Level : " + level.str());

    std::ostringstream xp;
    xp << Creature::getXp();

    std::ostringstream maxXp;
    maxXp << Creature::getMaxXp();

    Console::log("XP : " + xp.str() + "/" + maxXp.str());

    Entity::stats();
}