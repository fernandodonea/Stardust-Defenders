#include "../include/managers/resource_manager.h"

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
    for(auto &i : this->m_textures)
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
    return this->m_textures[key];
}
sf::Font& ResourceManager::GetFont()
{
    return this->m_font;  
}


/*
---------------
    Functions
---------------
*/
void ResourceManager::LoadFont()
{
    //Load font
    if(!this->m_font.loadFromFile("resources/fonts/Dosis.ttf"))
        std::cout<<"ERROR::RESOURCE_MANAGER:: Failed to load font"<<"\n";
}
void ResourceManager::LoadTextures()
{
    this->m_textures["PLAYER"] = new sf::Texture();
    this->m_textures["PLAYER"]->loadFromFile("resources/textures/purple-spaceship.png");
    
    this->m_textures["BACKGROUND"] = new sf::Texture();
    this->m_textures["BACKGROUND"]->loadFromFile("resources/textures/starry_background.png");

    this->m_textures["BULLET"] = new sf::Texture();
    this->m_textures["BULLET"]->loadFromFile("resources/textures/cyan-bullet.png");

    this->m_textures["ASTEROID_NORMAL"] = new sf::Texture();
    this->m_textures["ASTEROID_NORMAL"]->loadFromFile("resources/textures/asteroid_1.png");

    this->m_textures["ASTEROID_FAST"] = new sf::Texture();
    this->m_textures["ASTEROID_FAST"]->loadFromFile("resources/textures/asteroid_2.png");

    this->m_textures["ASTEROID_TANK"] = new sf::Texture();
    this->m_textures["ASTEROID_TANK"]->loadFromFile("resources/textures/asteroid_3.png");

    this->m_textures["ALIEN"] = new sf::Texture();
    this->m_textures["ALIEN"]->loadFromFile("resources/textures/green-spaceship.png");
}
