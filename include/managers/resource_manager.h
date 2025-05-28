/*

ResourceManager manages game resources such as textures and fonts.

Responsible for loading, storing, and providing access to all game resources, 
ensuring each is loaded only once.

*/


#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

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
