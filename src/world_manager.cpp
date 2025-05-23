#include "../include/world_manager.h"

/*
--------------------------------
    Constructor and destructor
--------------------------------
*/

WorldManager::WorldManager()
{
    //Load background
    if(!this->m_world_background_texture.loadFromFile("resources/textures/starry_background.png"))
        std::cout<<"ERROR::GAME::_INITWORLD: Failed to load background"<<"\n";

    this->m_world_background.setTexture(this->m_world_background_texture);

    //Innit System
    this->points=0;
}

WorldManager::~WorldManager()
{

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