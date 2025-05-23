#include "../include/player.h" 



//Private Functions

void Player::_InitVariables()
{
    this->m_movement_speed=5.f;

    this->m_attack_cooldown_max=10.f;
    this->m_attack_cooldown=this->m_attack_cooldown_max;

    this->m_hp_max=100;
    this->m_hp=this->m_hp_max;
    
}

void Player::_InitTexture()
{
    //Load texture from file 
    if(!this->m_texture.loadFromFile("resources/textures/spaceship.png"))
    {
        std::cout<<"ERROR:PLAYER::_INITTEXTURE: Could not load texture file"<<"\n";
    }
}

void Player::_InitSprite()
{
    //Set the texture to the sprite
    this->m_sprite.setTexture(this->m_texture);

    //Resize the sprite 
    this->m_sprite.scale(0.3f,0.3f);

    //Set the player in the center of the speed
    SetPosition(
        512.f-this->m_sprite.getGlobalBounds().width,
        364.f-this->m_sprite.getGlobalBounds().height);
} 



//Constructor and destructor
Player::Player()
{
    this->_InitVariables();
    this->_InitTexture();
    this->_InitSprite();

}

Player::~Player()
{

}



//Accesors
const int& Player::GetHp() const
{
    return this->m_hp;

}
const int& Player::GetHpMax() const
{
    return this->m_hp_max; 

} 


//Modifiers
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


//Functions
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