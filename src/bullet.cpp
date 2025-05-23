#include "../include/bullet.h"


void Bullet::_InitVariables()
{
    this->m_movement_speed=8.f;

    this->m_damage=10;

    this->m_direction=up;
    

}
void Bullet::_InitTexture()
{
    //Load texture from file 
    if(!this->m_texture.loadFromFile("resources/textures/cyan-bullet.png"))
    {
        std::cout<<"ERROR:BULLET::_INITTEXTURE: Could not load texture file"<<"\n";
    }

}
void Bullet::_InitSprite()
{
    this->m_sprite.setTexture(this->m_texture);
    this->m_sprite.setScale(0.5f,0.5f);
}

//Constructor and destructor
Bullet::Bullet()
{

}
Bullet::Bullet (float pos_x, float pos_y)
{
    _InitVariables();
    _InitTexture();
    _InitSprite();
    this->m_sprite.setPosition(pos_x,pos_y);
}
Bullet::~Bullet()
{

}

