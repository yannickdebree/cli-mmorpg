#ifndef COMMAND_EXECUTOR_H
#define COMMAND_EXECUTOR_H

#include <universe/world.h>
#include <universe/creature.h>
#include <vector>
#include <iostream>

class CommandExecutor
{
private:
    World *world;
    Creature *creature;
    std::string input;
    std::vector<std::string> terms;
    std::string getTerm(int rank);
    static void help();
    static bool resolve();

public:
    CommandExecutor(World *world, Creature *creature, std::string input);
    ~CommandExecutor();
    bool run();
};

#endif