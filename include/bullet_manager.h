#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H

#include "bullet.h"

class BulletManager
{
    private:
        std::vector<Bullet*> m_bullets;
        
        sf::RenderWindow *m_window;

    public:
        BulletManager();
        BulletManager(sf::RenderWindow *window);
        ~BulletManager();

        std::vector<Bullet*>& GetBullets();

        void WorldCollision();
        void Update();
};


#endif//BULLET_MANAGER_H