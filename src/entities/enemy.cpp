#include "../include/entities/enemy.h"









/*
--------------
    Getters
--------------
*/
const int& Enemy::GetType() const
{
    return this->m_type; 
}
const int& Enemy::GetHp() const
{
    return this->m_hp;
}
const int& Enemy::GetPoints() const
{
    return this->m_points; 
}
const int&Enemy::GetDamage() const
{
    return this->m_damage; 
}

/*
--------------
    Functions
-------------
*/

void Enemy::LoseHp(const int value)
{
    this->m_hp-=value;
    if(this->m_hp<0)
        this->m_hp=0;
}

void Enemy::Update()
{
    Move(down);
}
