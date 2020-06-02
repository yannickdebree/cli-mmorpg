#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <iostream>

void showLoginScreen();
bool authenticate(std::string pseudo, std::string plainPassword);

#endif