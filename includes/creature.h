#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
private:
    int x;
    int y;
    int level;
    int xp;
    int maxXp;
    int lp;
    int maxLp;
    int mp;
    int maxMp;
    int moving; // Time in milliseconds the creature spent to move to a near position.

public:
    Creature(int maxLp = 100, int maxMp = 75, int moving = 100);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getLevel();
    int getXp();
    int getMapXp();
    int getLp();
    int getMaxLp();
    int getMp();
    int getMaxMp();
    int getMooving();
    virtual void showStats();
};

#endif