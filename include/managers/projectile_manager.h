/*

ProjectileManager manages all the bullets and lasers shot by the player and enemies.

Responsible for creating, updating, and deleting Projectile objects, 
updating their positions, and handling memory management.

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