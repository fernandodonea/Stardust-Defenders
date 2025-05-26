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

bool Projectile::IsOutOfScreen()
{
   sf::FloatRect bounds=GetBounds();
   // Left
   if (bounds.left+bounds.width < 0.f)
        return true;
    // Right
    if (bounds.left>1024.f)
        return true;
    // Top
    if (bounds.top + bounds.height < 0.f)
        return true;
    // Bottom
    if (bounds.top >728.f)
        return true;

    return false;

}
void Projectile::Update()
{
   //Movement
   Move(m_direction.x, m_direction.y);
}