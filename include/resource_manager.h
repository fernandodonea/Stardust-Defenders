#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>

class ResourceManager
{
    private:
        std::map<std::string, sf::Texture*> textures;
        sf::Font font;
    public:
        ResourceManager();
        ~ResourceManager();

        void LoadTextures();
        void LoadFont();
        sf::Texture* GetTexture(const std::string& key);
        sf::Font& GetFont();
};


#endif //RESOURCE_MANAGER_H
