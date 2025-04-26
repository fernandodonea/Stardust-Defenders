#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>


#include <iostream>


class Bullet
{
    private:
        sf::Sprite shape;

        sf::Vector2f direction;
        float movement_speed;


    public:
        //Constructor and destructor
        Bullet();
        Bullet(sf::Texture* texture, float pos_x, float pos_y,
             float dir_x, float dir_y, float movement_speed);
        virtual ~Bullet();

        //Accesors
        const sf::FloatRect GetBounds() const;

        //Functions
        void Update();
        void Render(sf::RenderTarget* target);

};




#endif // BULLET_H