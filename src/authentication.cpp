#include <authentication.h>
#include <console.h>
#include <iostream>

void showLoginScreen()
{
    clear();
    printLine("Welcome to a fantastic world !");

    bool isAuthenticated = false;

    std::string pseudo;
    std::string plainPassword;

    while (!isAuthenticated)
    {
        printLine("Pseudo :");
        pseudo = prompt();

        printLine("Password :");
        plainPassword = prompt();

        if (authenticate(pseudo, plainPassword))
        {
            isAuthenticated = true;
        }
        else
        {
            printLine("Pseudo or password wrong... Retry.");
        }
    }
}

bool authenticate(std::string pseudo, std::string plainPassword)
{
    return pseudo == "test" && plainPassword == "test";
}