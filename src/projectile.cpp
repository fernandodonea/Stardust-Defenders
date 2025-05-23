#include "../include/projectile.h" 


const int& Projectile::GetDamage() const
{
   return this->m_damage;
}
void Projectile::Update()
{
   //Movement
   Move(m_direction.x, m_direction.y);
}