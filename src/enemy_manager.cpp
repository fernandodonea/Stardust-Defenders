#include "../include/enemy_manager.h"

/*
-------------------------------
    Constructor and destructor
-------------------------------
*/

EnemyManager::EnemyManager(sf::Texture* texture1,sf::Texture* texture2,sf::Texture* texture3,sf::Texture* texture4)
{
    m_textures.push_back(texture1);
    m_textures.push_back(texture2);
    m_textures.push_back(texture3);
    m_textures.push_back(texture4);
    
    this->m_spawn_timer_max=50.f;
    this->m_spawn_timer=this->m_spawn_timer_max;
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
std::vector<Enemy*>& EnemyManager::GetEnemies()
{
    return this->m_enemies;
}

/*
---------------
    Functions
---------------
*/

float EnemyManager::RandomLocation(sf::RenderWindow *window)
{
    return rand()%window->getSize().x-80.f;
}
int EnemyManager::RandomType()
{
    //Spawn rate
    int x=rand()%100+1;
    int type;

    if(x>=1 && x<=60)
        type=1;
    else if(x>60 && x<=90)
        type=2;
    else if(x>90 && x<=100)
        type=3;
    return type;
}

bool EnemyManager::AlienAlive()
{
    for(auto *e:m_enemies)
    {
        if (dynamic_cast<Alien*>(e) != nullptr)
            return true;
    }
    return false;
}


void EnemyManager::SpawnAsteroids(sf::RenderWindow *window)
{
    this->m_spawn_timer+=0.5f;
    if(this->m_spawn_timer >= this->m_spawn_timer_max)
    {
        int type=RandomType();
        this->m_enemies.push_back(
            new Asteroid(
                type,
                m_textures[type-1],
                RandomLocation(window), -100.f
            ));
        this->m_spawn_timer=0.f;
    }
}
void EnemyManager::SpawnAlien(sf::RenderWindow *window)
{
    this->m_enemies.push_back(
        new Alien(
            m_textures[3],
                WINDOW_WIDTH/2-SPRITE_MARGIN/2, 50.f
        )
    );
}


void EnemyManager::SpawnEnemies(sf::RenderWindow *window)
{
    if(AlienAlive())
        return;

    int destroyed=Asteroid::GetAsteroidsDestroyed();
    if (destroyed - m_last_alien_spawn_kill_count >= 10 && destroyed > 0)
    {
        SpawnAlien(window);
        m_last_alien_spawn_kill_count = destroyed;
        return;
    }

    SpawnAsteroids(window);
}

void EnemyManager::WorldCollision(sf:: RenderWindow *window)
{
    unsigned counter=0; 
    for(auto *asteroid: this->m_enemies)
    {
        //Enemy moving down
        asteroid->Update();

        // Enemy culling (Bottom of the screen)
        if(asteroid->GetBounds().top > window->getSize().y)
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

