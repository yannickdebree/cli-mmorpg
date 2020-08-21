#include <command.h>
#include <console.h>
#include <creature.h>
#include <iostream>

Command resolveCommand(std::string command)
{
    if (command == "clear")
    {
        return Command::Clear;
    }
    if (command == "exit")
    {
        return Command::Exit;
    }
    else if (command == "help")
    {
        return Command::Help;
    }
    else if (command.rfind("move", 0) == 0)
    {
        return Command::Move;
    }
    else if (command == "stats")
    {
        return Command::Stats;
    }
    else
    {
        return Command::Unknown;
    }
}

void showHelp()
{
    printLine("Available commands : ");
    printLine("- exit: exit the game (you will be transfered to your default checkpoint).");
    printLine("- help: Show all the possibles commands.");
    printLine("- move [(<x> <y>) | <destination>] : Move yourself to a destination.");
    printLine("- stats: Show the statistics of your character.");
}

void showUnknowCommand(std::string command)
{
    printLine("Command not found : " + command + ".");
}