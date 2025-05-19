#include "../include/resource_manager.h"

/*
-------------------------------
    Constructor and destructor
-------------------------------
*/

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


/*
-------------
    Getters
-------------
*/
sf::Texture* ResourceManager::GetTexture(const std::string& key)
{
    return this->textures[key];
}
sf::Font& ResourceManager::GetFont()
{
    return this->font;  
}


/*
---------------
    Functions
---------------
*/
void ResourceManager::LoadFont()
{
    //Load font
    if(!this->font.loadFromFile("resources/fonts/Dosis.ttf"))
        std::cout<<"ERROR::RESOURCE_MANAGER:: Failed to load font"<<"\n";
}
void ResourceManager::LoadTextures()
{
    this->textures["PLAYER"] = new sf::Texture();
    this->textures["PLAYER"]->loadFromFile("resources/textures/spaceship.png");
    
    this->textures["BACKGROUND"] = new sf::Texture();
    this->textures["BACKGROUND"]->loadFromFile("resources/textures/starry_background.png");

    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("resources/textures/cyan-bullet.png");

    this->textures["ASTEROID_NORMAL"] = new sf::Texture();
    this->textures["ASTEROID_NORMAL"]->loadFromFile("resources/textures/asteroid_1.png");

    this->textures["ASTEROID_FAST"] = new sf::Texture();
    this->textures["ASTEROID_FAST"]->loadFromFile("resources/textures/asteroid_2.png");

    this->textures["ASTEROID_TANK"] = new sf::Texture();
    this->textures["ASTEROID_TANK"]->loadFromFile("resources/textures/asteroid_3.png");
}
