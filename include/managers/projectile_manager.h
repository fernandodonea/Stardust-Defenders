/*
* @class ProjectileManager
* @brief Manages all the bullets shot by the player.

    ProjectileManager is responsible for creating, updating, and deleting Bullet objects.

    It updates bullet positions, checks for collisions with world boundaries (removing bullets that leave the screen),
    and provides access to the current list of active bullets for rendering or collision detection.

    ProjectileManager also ensures proper memory management by deleting bullets when they leave the screen.
*/


#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H


#include "../entities/bullet.h"
#include "../entities/laser.h"

#include "../entities/player.h"


class ProjectileManager
{
    private:
        std::vector<Projectile*> m_bullets;

        std::vector<Projectile*> m_lasers;
        
        sf::RenderWindow *m_window;

    public:
        //Constructor and destructor
        ProjectileManager()=default;
        ~ProjectileManager();

        //Getters
        std::vector<Projectile*>& GetBullets();

        std::vector<Projectile*>& GetLasers();

        //Functions
        void PlayerShoot(Player* player, sf::Texture* bullet_texture);
        void AlienShoot(sf::Texture* laser_texture, float pos_x, float pos_y, sf::Vector2f direction);

        void Update();
};


#endif//PROJECTILE_MANAGER_H