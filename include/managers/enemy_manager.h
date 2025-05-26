/*
* @class EnemyManager
* @brief Handles the enemies spawning and despawning

    EnemyManager is responsible for spawning the enemies above the screen
  at a random location.
  
    It also deletes the enemies once they leave the screen.
*/



#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "../entities/asteroid.h"
#include "../entities/alien.h"
#include "../entities/player.h"

#include "bullet_manager.h"

class EnemyManager
{
    private:
        float m_spawn_timer;
        float m_spawn_timer_max;

        int m_last_alien_spawn_kill_count=0;
        std::vector<Enemy*> m_enemies;
        std::vector<sf::Texture*> m_textures; 

        ProjectileManager* m_projectile_manager = nullptr;

    public:
        //Constructor and destructor
        EnemyManager(sf::Texture* asteroid_normal_texture,sf::Texture* asteroid_fast_texture,
            sf::Texture* asteroid_tank_texture,sf::Texture* alien_texture);
        ~EnemyManager();

        //Getter
        std::vector<Enemy*>& GetEnemies();
        
        //Functions
        void SetProjectileManagerForAliens(ProjectileManager* mgr);

        float RandomLocation(sf::RenderWindow *window);
        int RandomType();

        bool AlienAlive();

        void SpawnAsteroids(sf::RenderWindow *window);
        void SpawnAlien(sf::RenderWindow *window);

        void SpawnEnemies(sf::RenderWindow *window);
        void WorldCollision(sf:: RenderWindow *window);

        
        void Update(sf:: RenderWindow *window,sf::Texture* alien_laser_texture);
};


#endif//ENEMY_MANAGER_H