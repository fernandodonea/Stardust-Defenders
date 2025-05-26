#include "../include/managers/input_manager.h"


/*
---------------
    Functions
---------------
*/

void InputManager::Movement(Player* player)
{

    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player->Move(left);
    //Right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->Move(right);
    //Up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player->Move(up);
    //Down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player->Move(down);
}

void InputManager::Attack(Player* player,std::vector<Projectile*>&projectiles)
{
    //Shoot Bullets
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->CanAttack())
    {
        projectiles.push_back(
            new Bullet(
                player->GetPosition().x + player->GetBounds().width/2.f-12.f,
                player->GetPosition().y
            )
        );
    }
}

void InputManager::Update(Player* player,std::vector<Projectile*>&projectiles)
{
    Movement(player);
    Attack(player,projectiles);
}