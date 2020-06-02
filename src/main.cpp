#include <authentication.h>
#include <console.h>
#include <command.h>
#include <iostream>
#include <player.h>
#include <races/human.h>
#include <travel.h>
#include <word.h>

int main()
{
    showLoginScreen();

    clear();

    /**
     * Fake data.
     */
    World *world = new World("Azeroth", 100, 100);

    Player *player = new Player("jeanmartin");
    Human *creature = new Human("Aslan");

    player->addCreature(creature);
    world->placeCreature(creature, 50, 50);
    /**
     *
     */

    bool exit = false;

    printL("Welcome, " + player->getPseudo() + " !");
    printL("What do you want to do (enter \"help\" to get all possible commands) ?");

    while (!exit)
    {
        std::string command = prompt();

        switch (resolveCommand(command))
        {
        case Command::Clear:
            clear();
            break;
        case Command::Exit:
            exit = true;
            break;

        case Command::Help:
            showHelp();
            break;

        case Command::Move:
            // TODO : implement command parsing to get new position
            world->moveCreature(creature, creature->getX() + 1, creature->getY() + 1);
            break;

        case Command::Stats:
            creature->showStats();
            break;

        default:
        case Command::Unknown:
            showUnknowCommand(command);
            break;
        }
    }

    printL("Bye bye !");

    delete world;

    return 0;
}