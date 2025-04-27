#include "../include/enemy.h"


//Private functions
void Enemy::_InitVariables()
{
    this->type=rand()%8+3;

    this->speed=static_cast<float>(this->type/2);

    this->hp_max=static_cast<int>(this->type);
    this->hp=this->hp_max;
    
    this->damage=this->type;
    this->points=10*this->type;
    
}

void Enemy::_InitShape()
{
    this->shape.setRadius(this->type*4);
    this->shape.setPointCount(this->type);
    this->shape.setFillColor(sf::Color(rand()%255+1,rand()%255+1,rand()%255+1,255));
}


//Constructor and Destructor
Enemy::Enemy()
{

}
Enemy::Enemy(float pos_x, float pos_y)
{
    this->_InitVariables(); 
    this->_InitShape();
    
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
const unsigned Enemy::GetPoints() const
{
    return this->points; 
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