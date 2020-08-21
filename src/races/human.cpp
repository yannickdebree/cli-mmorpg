#include <creature.h>
#include <console.h>
#include <iostream>
#include <races/human.h>

Human::Human(std::string name) : Creature(100, 75, 200)
{
    Human::name = name;
}

std::string Human::getName()
{
    return Human::name;
}

void Human::showStats()
{
    printLine("Name : " + Human::getName());
    printLine("Race : Human");
    Creature::showStats();
}
