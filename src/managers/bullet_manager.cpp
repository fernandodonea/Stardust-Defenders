#include "../include/managers/bullet_manager.h"


/*
--------------
    Template
--------------
*/
template<typename T>
void ProjectileCollision(std::vector<T*>& projectiles)
{
    unsigned counter = 0;
    for (auto* proj : projectiles)
    {
        proj->Update();
        if (proj->IsOutOfScreen())
        {
            delete projectiles.at(counter);
            projectiles.erase(projectiles.begin() + counter);
        }
        else
        {
            ++counter;
        }
    }
}



/*
------------------
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


void ProjectileManager::Update()
{
    ProjectileCollision(m_bullets);
    ProjectileCollision(m_lasers);
}
