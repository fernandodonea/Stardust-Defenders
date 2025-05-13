#include "../include/resource_manager.h"


ResourceManager::ResourceManager()
{
    //Load font
    this->LoadFont();

    //Load textures
    this->LoadTextures();

}
ResourceManager::~ResourceManager()
{
    //Delete texture to avoid memory leak
    for(auto &i : this->textures)
    {
        delete i.second;
    }

}

void ResourceManager::LoadFont()
{
    //Load font
    if(!this->font.loadFromFile("resources/fonts/Dosis.ttf"))
        std::cout<<"ERROR::RESOURCE_MANAGER:: Failed to load font"<<"\n";
}
void ResourceManager::LoadTextures()
{
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("resources/textures/cyan-bullet.png");
}
sf::Texture* ResourceManager::GetTexture(const std::string& key)
{
    return this->textures[key];
}
sf::Font& ResourceManager::GetFont()
{
    return this->font;  
}