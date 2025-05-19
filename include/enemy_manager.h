/*
* @class EnemyManager
* @brief Handles the enemies spawning and despawning

    EnemyManager is responsible for spawning the enemies above the screen
  at a random location.
  
    It also deletes the enemies once they leave the screen.
*/



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
        //Constructor and destructor
        EnemyManager();
        ~EnemyManager();

        //Getter
        std::vector<Asteroid*>& GetAsteroids();
        
        //Functions
        void SpawnEnemies(sf::RenderWindow *window);
        void WorldCollision(sf:: RenderWindow *window);

        void Update(sf:: RenderWindow *window);
};


#endif//ENEMY_MANAGER_H