#include "../include/entities/projectile.h" 


/*
---------------
   Destructor
--------------
*/
Projectile::~Projectile()
{

}

/*
-----------
   Getter
-----------
*/
const int& Projectile::GetDamage() const
{
   return this->m_damage;
}



/*
--------------
   Functions
--------------
*/
void Projectile::Update()
{
   //Movement
   Move(m_direction.x, m_direction.y);
}