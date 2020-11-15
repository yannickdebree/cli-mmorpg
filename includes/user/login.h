#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>

class Login
{
private:
    bool authenticate(std::string pseudo, std::string plainPassword);

public:
    Login();
};

#endif