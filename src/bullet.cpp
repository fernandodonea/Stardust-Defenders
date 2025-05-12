#include "../include/bullet.h"


void Bullet::_InitVariables()
{
    this->movement_speed=8.f;

    this->damage=10;

    this->direction=up;
    

}
void Bullet::_InitTexture()
{
    //Load texture from file 
    if(!this->texture.loadFromFile("resources/textures/cyan-bullet.png"))
    {
        std::cout<<"ERROR:BULLET::_INITTEXTURE: Could not load texture file"<<"\n";
    }

}
void Bullet::_InitSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.5f,0.5f);
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
    this->sprite.setPosition(pos_x,pos_y);
}
Bullet::~Bullet()
{

}

