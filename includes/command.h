#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

enum Command
{
    Clear,
    Exit,
    Help,
    Move,
    Stats,
    Unknown,
};

Command resolveCommand(std::string command);
void showHelp();
void showUnknowCommand(std::string command);

#endif