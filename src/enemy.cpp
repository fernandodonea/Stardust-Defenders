#include "enemy.h"


//Private functions
void Enemy::_InitShape()
{
    this->shape.setRadius(rand()%20+20);
    this->shape.setPointCount(rand()%5+3);


}
void Enemy::_InitVariables()
{
    this->type=0;
    
    this->hp_max=10;
    this->hp=0;

    this->damage=1;
    this->points=5;

}



//Constructor and Destructor
Enemy::Enemy()
{

}
Enemy::Enemy(float pos_x, float pos_y)
{
    this->_InitShape();
    this->_InitVariables();

    this->shape.setPosition(pos_x,pos_y);

} 
Enemy::~Enemy()
{
    
}


//Functions
void Enemy::Update()
{

}
void Enemy::Render(sf::RenderTarget* target)
{
    target->draw(this->shape); 
}