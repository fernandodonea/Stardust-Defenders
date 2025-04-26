#include "../include/enemy.h"


//Private functions
void Enemy::_InitShape()
{
    this->shape.setRadius(rand()%20+20);
    this->shape.setPointCount(rand()%5+3);
    this->shape.setFillColor(sf::Color(rand()%255+1,rand()%255+1,rand()%255+1,255));


}
void Enemy::_InitVariables()
{
    this->type=0;
    this->speed=5.f;
    
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


//Accesors
const sf::FloatRect Enemy::GetBounds() const
{
    return this->shape.getGlobalBounds();
}

//Functions
void Enemy::Update()
{
    this->shape.move(0.f,this->speed);

}
void Enemy::Render(sf::RenderTarget* target)
{
    target->draw(this->shape); 
}