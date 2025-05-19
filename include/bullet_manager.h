/*
* @class BulletManager
* @brief Manages all the bullets shot by the player.

    BulletManager is responsible for creating, updating, and deleting Bullet objects.

    It updates bullet positions, checks for collisions with world boundaries (removing bullets that leave the screen),
    and provides access to the current list of active bullets for rendering or collision detection.

    BulletManager also ensures proper memory management by deleting bullets when they leave the screen.
*/


#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H

#include "bullet.h"

class BulletManager
{
    private:
        std::vector<Bullet*> m_bullets;
        
        sf::RenderWindow *m_window;

    public:
        //Constructor and destructor
        BulletManager();
        ~BulletManager();

        //Getters
        std::vector<Bullet*>& GetBullets();

        //Functions
        void WorldCollision();
        void Update();
};


#endif//BULLET_MANAGER_H