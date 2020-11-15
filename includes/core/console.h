#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>
#include <iostream>

class Console
{
private:
    static std::vector<std::string> history;

public:
    static void clear();
    static void log(std::string line);
    static std::string terminal();
};

#endif