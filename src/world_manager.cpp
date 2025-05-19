#include "../include/world_manager.h"


WorldManager::WorldManager()
{
    //Load background
    if(!this->world_background_texture.loadFromFile("resources/textures/starry_background.png"))
        std::cout<<"ERROR::GAME::_INITWORLD: Failed to load background"<<"\n";

    this->world_background.setTexture(this->world_background_texture);

    //Innit System
    this->points=0;

}
WorldManager::~WorldManager()
{

}


const sf::Sprite& WorldManager::GetBackground() const 
{
    return this->world_background;
}
int WorldManager::GetPoints() const 
{
    return this->points;
}

void WorldManager::SetPoints(int value)
{
    this->points=value;
}
void WorldManager::AddPoints(int value)
{
    SetPoints(this->points+value);
}

void WorldManager::Render(sf::RenderTarget& target)
{
    target.draw(this->world_background);
}