#include "../include/managers/bullet_manager.h"


/*
----------------
    Destructor
------------------
*/
ProjectileManager::~ProjectileManager()
{
    // Delete any bullets left
    for(auto *i: this->m_projectiles)
    {
        delete i;
    }
}



/*
----------------
    Getters
----------------
*/

std::vector<Projectile*>& ProjectileManager::GetProjectiles()
{
    return this->m_projectiles;
}



/*
---------------
    Functions
---------------
*/

//Handles the collision of bullets with the world boundaries
void ProjectileManager::WorldCollision()
{
    unsigned counter=0;

    for(auto *bullet: this->m_projectiles)
    {   
        //Bullet Movement
        bullet->Update();

        // Bullet culling (top of the screen)
        if(bullet->GetBounds().top + bullet->GetBounds().height < 0.f)
        {
            //Delete bullet
            delete this->m_projectiles.at(counter);
            this->m_projectiles.erase(this->m_projectiles.begin()+counter);          
        }
        ++counter;
    }
}


void ProjectileManager::Update()
{
    WorldCollision();
}
