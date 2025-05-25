#include "../include/managers/bullet_manager.h"


/*
----------------
    Destructor
------------------
*/
BulletManager::~BulletManager()
{
    // Delete any bullets left
    for(auto *i: this->m_bullets)
    {
        delete i;
    }
}



/*
----------------
    Getters
----------------
*/

std::vector<Bullet*>& BulletManager::GetBullets()
{
    return this->m_bullets;
}



/*
---------------
    Functions
---------------
*/

//Handles the collision of bullets with the world boundaries
void BulletManager::WorldCollision()
{
    unsigned counter=0;

    for(auto *bullet: this->m_bullets)
    {   
        //Bullet Movement
        bullet->Update();

        // Bullet culling (top of the screen)
        if(bullet->GetBounds().top + bullet->GetBounds().height < 0.f)
        {
            //Delete bullet
            delete this->m_bullets.at(counter);
            this->m_bullets.erase(this->m_bullets.begin()+counter);
            
        }
        ++counter;
    }
}


void BulletManager::Update()
{
    WorldCollision();
}
