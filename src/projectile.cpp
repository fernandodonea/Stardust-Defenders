#include "../include/projectile.h" 

Projectile::Projectile()
{

}

Projectile::~Projectile()
{

}

const int& Projectile::GetDamage() const
{
   return this->damage;
}
void Projectile::Update()
{
   //Movement
   Move(direction.x, direction.y);
}