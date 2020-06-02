#include <authentication.h>
#include <console.h>
#include <iostream>

void showLoginScreen()
{
    clear();
    printL("Welcome to a fantastic world !");

    bool isAuthenticated = false;

    std::string pseudo;
    std::string plainPassword;

    while (!isAuthenticated)
    {
        printL("Pseudo :");
        pseudo = prompt();

        printL("Password :");
        plainPassword = prompt();

        if (authenticate(pseudo, plainPassword))
        {
            isAuthenticated = true;
        }
        else
        {
            printL("Pseudo or password wrong... Retry.");
        }
    }
}

bool authenticate(std::string pseudo, std::string plainPassword)
{
    return pseudo == "test" && plainPassword == "test";
}