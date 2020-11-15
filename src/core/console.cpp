#include <core/console.h>
#include <iostream>

void Console::clear()
{
    std::cout << "\033c";
}

void Console::log(std::string line)
{
    std::cout << line << "\n";
}

std::string Console::terminal()
{
    std::cout << "/ ";

    int maxCommandSize = 50;

    char command[maxCommandSize];

    std::cin.getline(command, maxCommandSize);

    return command;
}