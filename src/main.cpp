#include <core/console.h>
#include <core/command-executor.h>
#include <universe/races/human.h>
#include <universe/world.h>
#include <user/login.h>
#include <user/player.h>

int main()
{
    try
    {
        new Login();

        Console::clear();

        /**
         * Fake data.
         */
        World *world = new World("Azeroth", 100, 100);

        Player *player = new Player("jeanmartin");
        Human *creature = new Human("Aslan");

        player->addCreature(creature);
        world->placeEntity(creature, 50, 50);
        /**
         *
         */

        bool exit = false;

        Console::log("Welcome, " + player->getPseudo() + " !");
        Console::log("What do you want to do (enter \"help\" to get all possible commands) ?");

        while (!exit)
        {
            CommandExecutor *commandExecutor = new CommandExecutor(world, creature, Console::terminal());

            exit = commandExecutor->run();
        }

        Console::log("You have been logged out, bye bye !");

        delete world;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Runtime error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}