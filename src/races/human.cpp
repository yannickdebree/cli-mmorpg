#include <console.h>
#include <iostream>
#include <races/human.h>

Human::Human(std::string name) : Creature(100, 75, 500)
{
    Human::name = name;
}

std::string Human::getName()
{
    return Human::name;
}

void Human::showStats()
{
    printL("Name : " + Human::getName());
    printL("Race : Human");
    Creature::showStats();
}
