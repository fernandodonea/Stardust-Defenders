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

void InputManager::Attack(Player* player, sf::Texture* bullet_texture)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_bulletManager) {
        m_bulletManager->PlayerShoot(player, bullet_texture);
    }
}

void InputManager::Update(Player* player, sf::Texture* bullet_texture)
{
    Movement(player);
    Attack(player, bullet_texture);
}