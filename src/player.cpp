#include "player.h" 



//Private Functions

void Player::_InitVariables()
{
    this->movement_speed=5.f;
    
}



void Player::_InitTexture()
{
    //Load texture from file 
    if(!this->texture.loadFromFile("textures/spaceship.png"))
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

    this->attack_cooldown_max=10.f;
    this->attack_cooldown=this->attack_cooldown_max;

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