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
const int& Enemy::GetPoints() const
{
    return this->points; 
}
const int&Enemy::GetDamage() const
{
    return this->damage; 
}

//Functions
void Enemy::Update()
{
    Move(down);
}
