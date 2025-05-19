#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "asteroid.h"
#include "player.h"

class EnemyManager
{
    private:
        float spawn_timer;
        float spawn_timer_max;
        std::vector<Asteroid*> m_enemies;

    public:
        EnemyManager();
        ~EnemyManager();

        std::vector<Asteroid*>& GetAsteroids();
        
        void SpawnEnemies(sf::RenderWindow *window);
        
        void WorldCollision(sf:: RenderWindow *window);

        void Update(sf:: RenderWindow *window);
};


#endif//ENEMY_MANAGER_H