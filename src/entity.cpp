#include "../include/entity.h"



// Getters
const sf::Vector2f& Entity::GetPosition() const
{
    return this->m_sprite.getPosition();
}

const sf::FloatRect Entity::GetBounds() const
{
    return this->m_sprite.getGlobalBounds();
}



// Setters
void Entity::SetPosition(const float x, const float y)
{
    this->m_sprite.setPosition(x, y);
}

void Entity::SetPosition(const sf::Vector2f pos)
{
    this->m_sprite.setPosition(pos);
}



// Functions
void Entity::Move(const float dir_x, const float dir_y)
{
    this->m_sprite.move(this->m_movement_speed * dir_x, this->m_movement_speed * dir_y);
}
void Entity::Move(const sf::Vector2f direction)
{
    this->m_sprite.move(direction*this->m_movement_speed);
}

void Entity::Render(sf::RenderTarget& target)
{
    target.draw(this->m_sprite);
}
