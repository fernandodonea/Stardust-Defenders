#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "asteroid.h"

class EnemyManager
{
    private:
        float spawn_timer;
        float spawn_timer_max;
        std::vector<Asteroid*> m_enemies;

        sf::RenderWindow *m_window;


    public:
        EnemyManager();
        EnemyManager(sf::RenderWindow *window);
        ~EnemyManager();

        std::vector<Asteroid*>& GetAsteroids();

        void WorldCollision();
        void SpawnEnemies();

        void Update();
};


#endif//ENEMY_MANAGER_H