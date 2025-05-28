#ifndef ENTITY_H
#define ENTITY_H


#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Vector2f up(0.f,-1.f);
const sf::Vector2f down(0.f,1.f);
const sf::Vector2f left(-1.f,0.f);
const sf::Vector2f right(1.f,0.f);

const sf::Vector2f diag_left(-0.7f, 1.f);
const sf::Vector2f diag_right(0.7f, 1.f);

class Entity
{
    protected:
        sf::Sprite m_sprite;
        sf::Texture m_texture;

        float m_movement_speed;

        //Protected functions
        virtual void _InitVariables()=0;
        void _InitSprite(sf::Texture* texture,float pos_x, float pos_y, float size);
    
    public:
        //Getters
        const sf::Vector2f& GetPosition() const;
        const sf::FloatRect GetBounds() const;
    
        //Setters
        void SetPosition(const float x, const float y);
        void SetPosition(const sf::Vector2f pos);
        void SetTexture(sf::Texture* texture);
        void SetSize(float size);
    
        // Functions
        void Move(const float dir_x, const float dir_y);
        void Move(const sf::Vector2f direction);

        virtual std::string ToString() const = 0;

        //operator << overload
        friend std::ostream& operator<<(std::ostream& os, const Entity& entity) {
        os << entity.ToString();
        return os;
        }

        
        virtual void Update() = 0;
        void Render(sf::RenderTarget& target);

};


#endif // ENTITY


