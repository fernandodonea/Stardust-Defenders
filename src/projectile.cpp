#include "../include/projectile.h" 


const int& Projectile::GetDamage() const
{
   return this->damage;
}
void Projectile::Update()
{
   //Movement
   Move(direction.x, direction.y);
}