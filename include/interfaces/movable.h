#ifndef MOVABLE_H
#define MOVABLE_H

#include <SFML/Graphics.hpp>

class Movable
{
    public:
        //Destructor
        virtual ~Movable() = default;

        //Functions
        virtual void Move(const float dir_x, const float dir_y)=0;
        virtual void Move(const sf::Vector2f direction)=0;

};

#endif // MOVABLE_H