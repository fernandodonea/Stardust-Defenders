#include "../include/managers/world_manager.h"

/*
-----------------
    Constructor 
------------------
*/
WorldManager::WorldManager(sf::Texture* texture)
{
    this->m_world_background.setTexture(*texture);

    //Innit System
    this->points=0;
}



/*
-------------
    Getters
-------------
*/

const sf::Sprite& WorldManager::GetBackground() const 
{
    return this->m_world_background;
}

int WorldManager::GetPoints() const 
{
    return this->points;
}



/*
-------------
    Setters
-------------
*/

void WorldManager::SetPoints(int value)
{
    this->points=value;
}
void WorldManager::AddPoints(int value)
{
    SetPoints(this->points+value);
}



/*
--------------
    Functions
--------------
*/

void WorldManager::Render(sf::RenderTarget& target)
{
    target.draw(this->m_world_background);
}