#include <core/command-executor.h>
#include <core/console.h>
#include <universe/creature.h>
#include <universe/world.h>
#include <user/move.h>
#include <user/player.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

CommandExecutor::CommandExecutor(World *world, Creature *creature, std::string input)
{
    CommandExecutor::world = world;
    CommandExecutor::creature = creature;
    CommandExecutor::input = input;

    std::stringstream ss(input);
    std::string item;

    while (std::getline(ss, item, ' '))
    {
        CommandExecutor::terms.push_back(item);
    }
}

CommandExecutor::~CommandExecutor()
{
    delete CommandExecutor::world;
    delete CommandExecutor::creature;
}

std::string CommandExecutor::getTerm(int rank)
{
    return CommandExecutor::terms[rank];
}

void CommandExecutor::help()
{
    Console::log("Available commands : ");
    Console::log("- clear: Clear the console.");
    Console::log("- exit: Exit the game (you will be transfered to your default checkpoint).");
    Console::log("- help: Show all the possibles commands.");
    Console::log("- move (<x> <y> | <x>.<y> | <place>) : Move your avatar to a destination.");
    Console::log("- exec <path>: Run a RPG script from a path.");
    Console::log("- stats: Show the statistics of your character.");
}

bool CommandExecutor::run()
{
    if (CommandExecutor::getTerm(0) == "clear")
    {
        Console::clear();
    }
    else if (CommandExecutor::getTerm(0) == "exit")
    {
        return true;
    }
    else if (CommandExecutor::getTerm(0) == "help")
    {
        CommandExecutor::help();
    }
    else if (CommandExecutor::getTerm(0) == "move")
    {
        // TODO : implement command parsing to get new position.
        Move *move = new Move(CommandExecutor::world, CommandExecutor::creature, CommandExecutor::creature->getX() + 1, CommandExecutor::creature->getY() + 1);
        move->start();
    }
    else if (CommandExecutor::getTerm(0) == "stats")
    {
        CommandExecutor::creature->stats();
    }
    else if (CommandExecutor::getTerm(0) == "exec")
    {
        // TODO : implement file path reading.
        std::string path = "scripts/example.rpg";

        std::ifstream file(path);

        if (file.is_open())
        {
            std::string line;

            bool exit = false;

            while (getline(file, line) || !exit)
            {
                std::cout << "Executing : " << line << std::endl;

                if (line.rfind("#", 0) != 0)
                {
                    // TODO : discriminate banned commands (exampe: "exec" is not allowed here).
                    exit = new CommandExecutor(CommandExecutor::world, CommandExecutor::creature, line);
                }

                Console::log("Script runned with success !");
            }

            file.close();
        }
        else
        {
            Console::log("Problem by reading file " + path + ": file not found or corrupted.");
        }
    }
    else
    {
        Console::log("Command not found : " + CommandExecutor::input + ". Enter 'help' to see all possible commands.");
    }
    return false;
}
