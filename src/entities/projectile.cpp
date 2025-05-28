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

const int& Projectile::GetType() const
{
   return this->m_type;

}
const sf::Vector2f& Projectile::GetDirection() const
{
   return this->m_direction;
}



/*
--------------
   Functions
--------------
*/
std::string Projectile::ToString() const
{
   std::string debug_message="";
   debug_message+="Projectyle(pos=)"+std::to_string(GetPosition().x) + "," + std::to_string(GetPosition().y)+")\n";
   
   std::string type;
   if(GetType() == 1)
      type="Bullet";
   else if(GetType() == 2)
      type="Laser";
   debug_message+="Type: "+type+"\n";

   std::string direction;
   if(GetDirection()==down)
      direction="Down";
   else if(GetDirection()==up)
      direction="Up";
   else if(GetDirection()==diag_left)
      direction="Diagonal Left";
   else if(GetDirection()==diag_right)
      direction="Diagnoal Right";
   debug_message+="Direction: "+direction+"\n\n";


   return debug_message;
}

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