#ifndef WORLD_MANAGER_H
#define WORLD_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>

class WorldManager
{
    private:
        //World 
        sf::Texture world_background_texture;
        sf::Sprite world_background;

        //Systems
        int points;
        
    public:
        WorldManager();
        ~WorldManager();

        const sf::Sprite& GetBackground() const;
        int GetPoints() const;

        void SetPoints(int value);
        void AddPoints(int value);

        void Render(sf::RenderTarget& target);


};

#endif //WORLD_MANAGER_H