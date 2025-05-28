#include "../include/entities/laser.h"


/*
------------------------
    Private function
-----------------------
*/
void Laser::_InitVariables()
{
    this->m_type=2;

    this->m_movement_speed=8.f;

    this->m_damage=30;
}


/*
----------------
    Constructor
----------------
*/

Laser::Laser(sf::Texture* texture,float pos_x, float pos_y, sf::Vector2f direction)
{
    _InitVariables();

    this->m_direction=direction;

    _InitSprite(texture,pos_x,pos_y,0.25f);

}
