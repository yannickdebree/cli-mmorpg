#include <core/console.h>
#include <universe/creature.h>
#include <user/player.h>

Player::Player(std::string pseudo)
{
    Player::pseudo = pseudo;
}

Player::~Player()
{
    int creaturesNbr = Player::creatures.size();
    for (int i = 0; i < creaturesNbr; ++i)
    {
        delete creatures[i];
    }
}

void Player::addCreature(Creature *creature)
{
    if (Player::creatures.size() == Player::creaturesNbrMax)
    {
        Console::log("Player can't have more creatures...");
        return;
    }
    Player::creatures.push_back(creature);
}

std::string Player::getPseudo()
{
    return pseudo;
}