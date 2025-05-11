#include "../include/entity.h"


//Constructor and destructor
Entity::Entity()
{

}

Entity::~Entity()
{

}



// Getters
const sf::Vector2f& Entity::GetPosition() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect Entity::GetBounds() const
{
    return this->sprite.getGlobalBounds();
}



// Setters
void Entity::SetPosition(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

void Entity::SetPosition(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}



// Functions
void Entity::Move(const float dir_x, const float dir_y)
{
    this->sprite.move(this->movement_speed * dir_x, this->movement_speed * dir_y);
}

void Entity::Render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}
