#include "../include/enemy_manager.h"

EnemyManager::EnemyManager()
{

}
EnemyManager::EnemyManager(sf::RenderWindow *window)
{
    this->m_window=window;

    this->spawn_timer_max=50.f;
    this->spawn_timer=this->spawn_timer_max;
}

EnemyManager::~EnemyManager()
{
    for(auto *i: this->m_enemies)
    {
        delete i;
    }
}


std::vector<Asteroid*>& EnemyManager::GetAsteroids()
{
    return this->m_enemies;
}


void EnemyManager::SpawnEnemies()
{
    this->spawn_timer+=0.5f;
    if(this->spawn_timer >= this->spawn_timer_max)
    {
        this->m_enemies.push_back(new Asteroid(rand()%this->m_window->getSize().x-80.f, -100.f));
        this->spawn_timer=0.f;
    }
}
void EnemyManager::WorldCollision()
{
    unsigned counter=0; 
    for(auto *enemy: this->m_enemies)
    {
        //Enemy moving down
        enemy->Update();

        // Enemy culling (Bottom of the screen)
        if(enemy->GetBounds().top > this->m_window->getSize().y)
        {
            //Delete Enemy
            delete this->m_enemies.at(counter);
            this->m_enemies.erase(this->m_enemies.begin()+counter);
             
        }
        counter++;
    }
}

void EnemyManager::Update()
{
    SpawnEnemies();
    WorldCollision();
}

