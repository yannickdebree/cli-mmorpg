#include <iostream>
#include <console.h>

void clear()
{
    std::cout << "\033c";
}

void printLine(std::string line)
{
    std::cout << line << "\n";
}

std::string prompt()
{
    std::cout << "/ ";

    int maxCommandSize = 50;

    char command[maxCommandSize];

    std::cin.getline(command, maxCommandSize);

    return command;
}