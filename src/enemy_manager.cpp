#include "../include/enemy_manager.h"

/*
-------------------------------
    Constructor and destructor
-------------------------------
*/

EnemyManager::EnemyManager()
{

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


/*
-------------
    Getter
-------------
*/
std::vector<Asteroid*>& EnemyManager::GetAsteroids()
{
    return this->m_enemies;
}

/*
---------------
    Functions
---------------
*/
void EnemyManager::SpawnEnemies(sf::RenderWindow *window)
{
    this->spawn_timer+=0.5f;
    if(this->spawn_timer >= this->spawn_timer_max)
    {
        this->m_enemies.push_back(new Asteroid(rand()%window->getSize().x-80.f, -100.f));
        this->spawn_timer=0.f;
    }
}

void EnemyManager::WorldCollision(sf:: RenderWindow *window)
{
    unsigned counter=0; 
    for(auto *enemy: this->m_enemies)
    {
        //Enemy moving down
        enemy->Update();

        // Enemy culling (Bottom of the screen)
        if(enemy->GetBounds().top > window->getSize().y)
        {
            //Delete Enemy
            delete this->m_enemies.at(counter);
            this->m_enemies.erase(this->m_enemies.begin()+counter);   
        }
        counter++;
    }
}


void EnemyManager::Update(sf:: RenderWindow *window)
{
    SpawnEnemies(window);
    WorldCollision(window);
}

