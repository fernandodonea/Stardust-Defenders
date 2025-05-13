#ifndef ENTITY_H
#define ENTITY_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>

const sf::Vector2f up(0.f,-1.f);
const sf::Vector2f down(0.f,1.f);
const sf::Vector2f left(-1.f,0.f);
const sf::Vector2f right(1.f,0.f);



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
        // Getters
        const sf::Vector2f& GetPosition() const;
        const sf::FloatRect GetBounds() const;
    
        // Setters
        void SetPosition(const float x, const float y);
        void SetPosition(const sf::Vector2f pos);
    
        // Functions
        void Move(const float dir_x, const float dir_y);
        void Move(const sf::Vector2f direction);
        
        virtual void Update() = 0;
        void Render(sf::RenderTarget& target);

};


#endif // ENTITY


