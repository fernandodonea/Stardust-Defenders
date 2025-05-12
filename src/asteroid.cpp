#include "../include/asteroid.h"

#include <iostream>

//Private functions
void Asteroid::_InitVariables()
{
    this->type=rand()%3+1;

    this->movement_speed=5.f;




    this->hp_max=10.f*this->type;
    this->hp=this->hp_max;
    
    this->damage=this->type;
    this->points=10*this->type;
    
}
void Asteroid::_InitTexture()
{
    //Load texture from file
    if(!this->texture.loadFromFile("resources/textures/asteroid_1.png"))
    {
        std::cout<<"ERROR:ASTEROID::_INITTEXTURE: Could not load texture file"<<"\n";
    }
}
void Asteroid::_InitSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.3f,0.3f); 
}


//Constructor and Destructor
Asteroid::Asteroid()
{

}
Asteroid::Asteroid(float pos_x, float pos_y)
{
    this->_InitVariables(); 
    this->_InitTexture();
    this->_InitSprite();
    
    this->sprite.setPosition(pos_x,pos_y);

} 
Asteroid::~Asteroid()
{
    
}

//Functions
void Asteroid::Update()
{
   Move(down);
}
