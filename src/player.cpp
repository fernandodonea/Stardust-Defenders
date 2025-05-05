#include "../include/player.h" 



//Private Functions

void Player::_InitVariables()
{
    this->movement_speed=5.f;

    this->attack_cooldown_max=10.f;
    this->attack_cooldown=this->attack_cooldown_max;

    this->hp_max=100;
    this->hp=this->hp_max;
    
}

void Player::_InitTexture()
{
    //Load texture from file 
    if(!this->texture.loadFromFile("resources/textures/spaceship.png"))
    {
        std::cout<<"ERROR:PLAYER::_INITTEXTURE: Could not load texture file"<<"\n";
    }
}

void Player::_InitSprite()
{
    //Set the texture to the sprite
    this->sprite.setTexture(this->texture);

    //Resize the sprite 
    this->sprite.scale(0.3f,0.3f);
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
const sf::Vector2f& Player::GetPosition() const
{
     return this->sprite.getPosition();
}

const sf::FloatRect Player::GetBounds() const
{
    return this->sprite.getGlobalBounds();

}

const int& Player::GetHp() const
{
    return this->hp;

}
const int& Player::GetHpMax() const
{
    return this->hp_max; 

} 


//Modifiers
void Player::SetPosition(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}
void Player::SetPosition(const float x, const float y)
{
    this->sprite.setPosition(x,y);

}

void Player::SetHp(const int hp)
{
    this->hp=hp;
}
void Player::LoseHp(const int value)
{
    this->hp-=value;
    if(this->hp<0)
        this->hp=0;
}


//Functions
void Player::Move(const float dir_x, const float dir_y)
{
    this->sprite.move(this->movement_speed*dir_x,this->movement_speed*dir_y);

}

const bool Player::CanAttack()
{
    if(this->attack_cooldown>=this->attack_cooldown_max)
    {
        this->attack_cooldown=0.f;
        return true;
    }
    return false;
}

void Player::UpdateAttack()
{
    if(this->attack_cooldown < this->attack_cooldown_max)
        this->attack_cooldown+=0.5f;


}


void Player::Update()
{
    this->UpdateAttack();

}

 
void Player::Render(sf::RenderTarget& target)
{
    target.draw(this->sprite);

}