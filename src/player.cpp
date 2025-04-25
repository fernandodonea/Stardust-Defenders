#include "player.h" 



//Private Functions
void Player::_InitTexture()
{
    //Load texture from file 

}
void Player::_InitSprite()
{
    //Set the texture to the sprite
    this->sprite.setTexture(this->texture);

} 



//Constructor and destructor
Player::Player()
{
    this->_InitTexture();
    this->_InitSprite();

}

Player::~Player()
{

}



//Functions
void Player::Update()
{


}

 
void Player::Render(sf::RenderTarget& target)
{
    target.draw(this->sprite);

}