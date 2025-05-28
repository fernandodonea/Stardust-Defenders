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
std::string Enemy::ToString() const
{
    std::string debug_message="";
    debug_message+="Enemy(pos="+std::to_string(GetPosition().x) + "," + std::to_string(GetPosition().y)+")\n";

    std::string type;
    if(GetType() == 1)
        type="Normal Asteroid";
    else if(GetType() == 2)
        type="Fast Asteroid";
    else if(GetType() == 3)
        type="Tank Asteroid";
    else if(GetType() == 4)
        type="Alien";

    debug_message+="Type: "+type+"\n";
    debug_message+="Dimensions:"+ std::to_string(GetBounds().width) + "x" + std::to_string(GetBounds().height)+"\n\n";
    return debug_message;
}

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
