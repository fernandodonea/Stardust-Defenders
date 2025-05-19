#include "../include/bullet_manager.h"



BulletManager::BulletManager()
{

}
BulletManager::BulletManager(sf::RenderWindow *window)
{
    this->m_window=window;

}
BulletManager::~BulletManager()
{
    // Delete any bullets left
    for(auto *i: this->m_bullets)
    {
        delete i;
    }
}

std::vector<Bullet*>& BulletManager::GetBullets()
{
    return this->m_bullets;
}

void BulletManager::WorldCollision()
{
    unsigned counter=0;

    for(auto *bullet: this->m_bullets)
    {   
        //Movement
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
