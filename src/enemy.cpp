#include "../include/enemy.h"






//Constructor and Destructor
Enemy::Enemy()
{

}
Enemy::~Enemy()
{
    
}


//Accesors
const int& Enemy::GetType() const
{
    return this->type; 
}
const int& Enemy::GetHp() const
{
    return this->hp;
}
const int& Enemy::GetPoints() const
{
    return this->points; 
}
const int&Enemy::GetDamage() const
{
    return this->damage; 
}

//Functions

void Enemy::LoseHp(const int value)
{
    this->hp-=value;
    if(this->hp<0)
        this->hp=0;
}

void Enemy::Update()
{
    Move(down);
}
