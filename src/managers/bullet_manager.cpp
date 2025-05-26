#include "../include/managers/bullet_manager.h"


/*
----------------
    Destructor
------------------
*/
ProjectileManager::~ProjectileManager()
{
    // Delete any bullets left
    for(auto *i: this->m_lasers)
    {
        delete i;
    }
}



/*
----------------
    Getters
----------------
*/

std::vector<Projectile*>& ProjectileManager::GetBullets()
{
    return this->m_bullets;
}


std::vector<Projectile*>& ProjectileManager::GetLasers()
{
    return this->m_lasers;
}


/*
---------------
    Functions
---------------
*/
void ProjectileManager::PlayerShoot(Player* player, sf::Texture* bullet_texture)
{
    if (player->CanAttack()) {
        m_bullets.push_back(
            new Bullet(
                bullet_texture,
                player->GetPosition().x + player->GetBounds().width/2.f - 12.f,
                player->GetPosition().y
            )
        );
    }
}

void ProjectileManager::AlienShoot(sf::Texture* laser_texture, float pos_x, float pos_y, sf::Vector2f direction)
{
    m_lasers.push_back(new Laser(laser_texture, pos_x, pos_y, direction));
}

void ProjectileManager::BulletCollison()
{
    unsigned counter = 0;
    for (auto* bullet : this->m_bullets)
    {
        bullet->Update();
        if (bullet->IsOutOfScreen())
        {
            delete this->m_bullets.at(counter);
            this->m_bullets.erase(this->m_bullets.begin() + counter);
        }
        else
        {
            ++counter;
        }
    }
}
void ProjectileManager::LaserCollision()
{
    unsigned counter = 0;
    for (auto* laser : this->m_lasers)
    {
        laser->Update();
        if (laser->IsOutOfScreen())
        {
            delete this->m_lasers.at(counter);
            this->m_lasers.erase(this->m_lasers.begin() + counter);
        }
        else
        {
            ++counter;
        }
    }
}

//Handles the collision of bullets with the world boundaries
void ProjectileManager::WorldCollision()
{
    BulletCollison();
    LaserCollision();
}


void ProjectileManager::Update()
{
    WorldCollision();
}
