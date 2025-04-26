#include "../include/bullet.h"



//Constructor and destructor
Bullet::Bullet()
{

}
Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y,
    float dir_x, float dir_y, float movement_speed)
{
    this->shape.setTexture(*texture);
    this->shape.setScale(0.3f,0.3f);

    this->shape.setPosition(pos_x,pos_y);

    this->direction.x=dir_x;
    this->direction.y=dir_y; 

    this->movement_speed=movement_speed;
}
Bullet::~Bullet()
{

}


//Accesors
const sf::FloatRect Bullet::GetBounds() const
{
    return this->shape.getGlobalBounds();
}


 //Functions
 void Bullet::Update()
 {
    //Movement
    this->shape.move(this->movement_speed*this->direction);


 }
 void Bullet::Render(sf::RenderTarget* target)
 {
    target->draw(this->shape);
     
 }