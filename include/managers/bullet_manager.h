/*
* @class ProjectileManager
* @brief Manages all the bullets shot by the player.

    ProjectileManager is responsible for creating, updating, and deleting Bullet objects.

    It updates bullet positions, checks for collisions with world boundaries (removing bullets that leave the screen),
    and provides access to the current list of active bullets for rendering or collision detection.

    ProjectileManager also ensures proper memory management by deleting bullets when they leave the screen.
*/


#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H

#include "../entities/bullet.h"


class ProjectileManager
{
    private:
        std::vector<Projectile*> m_projectiles;
        
        sf::RenderWindow *m_window;

    public:
        //Constructor and destructor
        ProjectileManager()=default;
        ~ProjectileManager();

        //Getters
        std::vector<Projectile*>& GetProjectiles();

        //Functions
        void WorldCollision();
        void Update();
};


#endif//BULLET_MANAGER_H