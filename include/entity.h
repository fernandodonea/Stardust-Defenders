#ifndef ENTITY_H
#define ENTITY_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>


class Entity
{
    protected:
        sf::Sprite sprite;
        sf::Texture texture;

        float movement_speed;

        virtual void _InitVariables()=0;
        virtual void _InitTexture()=0;
        virtual void _InitSprite()=0;
    
    public:
        //Constructor and destructor
        Entity();
        virtual ~Entity();
    
        // Getters
        virtual const sf::Vector2f& GetPosition() const;
        virtual const sf::FloatRect GetBounds() const;
    
        // Setters
        virtual void SetPosition(const float x, const float y);
        virtual void SetPosition(const sf::Vector2f pos);
    
        // Functions
        virtual void Move(const float dir_x, const float dir_y);
        virtual void Update() = 0;
        virtual void Render(sf::RenderTarget& target);

};


#endif // ENTITY


