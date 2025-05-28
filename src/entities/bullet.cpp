#include "../include/entities/bullet.h"


/*
-------------------------
    Private Functions
-------------------------
*/
void Bullet::_InitVariables()
{
    this->m_type=1;

    this->m_movement_speed=8.f;

    this->m_damage=10;

    this->m_direction=up;

}



/*
----------------
    Constructor 
------------------
*/
Bullet::Bullet (sf::Texture* texture,float pos_x, float pos_y)
{
    _InitVariables();

    _InitSprite(texture,pos_x,pos_y,0.5f);
}


