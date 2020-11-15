#ifndef CREATURE_H
#define CREATURE_H

#include <universe/entity.h>

class Creature : public Entity
{
private:
    int lp;
    int maxLp;
    int mp;
    int maxMp;
    int level;
    int xp;
    int maxXp;

public:
    Creature(int maxLp = 100, int maxMp = 75, int moving = 1000);
    int getLp();
    int getMaxLp();
    int getMp();
    int getMaxMp();
    int getLevel();
    int getXp();
    int getMaxXp();
    void stats();
};

#endif