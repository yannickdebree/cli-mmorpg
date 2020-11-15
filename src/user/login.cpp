#include <core/console.h>
#include <user/login.h>

Login::Login()
{
    Console::clear();
    Console::log("Welcome to a fantastic world !");

    bool isAuthenticated = false;

    std::string pseudo;
    std::string plainPassword;

    while (!isAuthenticated)
    {
        Console::log("Pseudo :");
        pseudo = Console::terminal();

        Console::log("Password :");
        plainPassword = Console::terminal();

        if (Login::authenticate(pseudo, plainPassword))
        {
            isAuthenticated = true;
        }
        else
        {
            Console::log("Pseudo or password wrong... Retry.");
        }
    }
}

bool Login::authenticate(std::string pseudo, std::string plainPassword)
{
    return pseudo == "test" && plainPassword == "test";
}