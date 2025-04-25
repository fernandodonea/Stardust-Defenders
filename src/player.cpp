#include "player.h" 



//Private Functions
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

} 



//Constructor and destructor
Player::Player()
{
    this->movement_speed=5.f;

    this->_InitTexture();
    this->_InitSprite();

}

Player::~Player()
{

}



//Functions
void Player::Move(const float dir_x, const float dir_y)
{
    this->sprite.move(this->movement_speed*dir_x,this->movement_speed*dir_y);

}



void Player::Update()
{


}

 
void Player::Render(sf::RenderTarget& target)
{
    target.draw(this->sprite);

}