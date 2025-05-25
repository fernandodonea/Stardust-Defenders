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
#include "alien.h"
#include "player.h"

class EnemyManager
{
    private:
        float m_spawn_timer;
        float m_spawn_timer_max;

        int m_last_alien_spawn_kill_count=0;
        std::vector<Enemy*> m_enemies;
        std::vector<sf::Texture*> m_textures; 

    public:
        //Constructor and destructor
        EnemyManager(sf::Texture* texture1,sf::Texture* texture2,sf::Texture* texture3,sf::Texture* texture4);
        ~EnemyManager();

        //Getter
        std::vector<Enemy*>& GetEnemies();
        
        //Functions
        float RandomLocation(sf::RenderWindow *window);
        int RandomType();

        bool AlienAlive();

        void SpawnAsteroids(sf::RenderWindow *window);
        void SpawnAlien(sf::RenderWindow *window);

        void SpawnEnemies(sf::RenderWindow *window);
        void WorldCollision(sf:: RenderWindow *window);

        
        void Update(sf:: RenderWindow *window);
};


#endif//ENEMY_MANAGER_H