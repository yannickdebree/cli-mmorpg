#include <core/console.h>
#include <universe/races/human.h>
#include <universe/creature.h>
#include <iostream>

Human::Human(std::string name) : Creature(100, 75, 500)
{
    Human::name = name;
}

std::string Human::getName()
{
    return Human::name;
}

void Human::stats()
{
    Console::log("Name : " + Human::getName());
    Console::log("Race : Human");
    Creature::stats();
}
