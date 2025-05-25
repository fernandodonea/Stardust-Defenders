#include "../include/player.h" 



/*
-----------------------
    Private functions
-----------------------
*/

void Player::_InitVariables()
{
    this->m_movement_speed=5.f;

    this->m_attack_cooldown_max=10.f;
    this->m_attack_cooldown=this->m_attack_cooldown_max;

    this->m_hp_max=100;
    this->m_hp=this->m_hp_max;
    
}


/*
--------------------------------
    Constructor and destructor
--------------------------------
*/
Player::Player(sf::Texture* texture)
{
    _InitVariables();

    float pos_x=512.f-this->m_sprite.getGlobalBounds().width;
    float pos_y=364.f-this->m_sprite.getGlobalBounds().height;

    _InitSprite(texture,pos_x,pos_y,0.4f);

}

Player::~Player()
{

}



/*
--------------
    Getters
--------------
*/
const int& Player::GetHp() const
{
    return this->m_hp;

}
const int& Player::GetHpMax() const
{
    return this->m_hp_max; 

} 


/*
------------
    Setter
------------
*/
void Player::SetHp(const int hp)
{
    this->m_hp=hp;
}
void Player::LoseHp(const int value)
{
    this->m_hp-=value;
    if(this->m_hp<0)
        this->m_hp=0;
}


/*
---------------
    Functions
---------------
*/
const bool Player::CanAttack()
{
    if(this->m_attack_cooldown>=this->m_attack_cooldown_max)
    {
        this->m_attack_cooldown=0.f;
        return true;
    }
    return false;
}
void Player::UpdateAttack()
{
    if(this->m_attack_cooldown < this->m_attack_cooldown_max)
        this->m_attack_cooldown+=0.5f;
}


void Player::Update()
{
    this->UpdateAttack();
}