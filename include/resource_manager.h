/*
@class ResourceManager
@brief Manages game resources such as textures and fonts.

    ResourceManager is responsible for loading, storing, and providing access to all game resources,
    including textures and fonts. 

    It ensures that each resource is loaded only once and is available
    throughout the game.

    ResourceManager also handles proper cleanup of resources to prevent memory leaks.
*/


#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>

class ResourceManager
{
    private:
        std::map<std::string, sf::Texture*> m_textures;
        sf::Font m_font;
    public:
        //Constructor and destructor
        ResourceManager();
        ~ResourceManager();

        //Getters
        sf::Texture* GetTexture(const std::string& key);
        sf::Font& GetFont();

        //Functions
        void LoadTextures();
        void LoadFont();
};


#endif //RESOURCE_MANAGER_H
