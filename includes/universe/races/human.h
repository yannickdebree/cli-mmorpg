#ifndef HERO_H
#define HERO_H

#include <universe/creature.h>
#include <iostream>

class Human : public Creature
{
private:
    std::string name;

public:
    Human(std::string name);
    std::string getName();
    void stats();
};

#endif