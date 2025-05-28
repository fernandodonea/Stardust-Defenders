/*
InputManager handles player input and input-driven actions.

Responsible for processing keyboard input and translating it into player actions 
such as movement and shooting.
*/


#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "../entities/player.h"
#include "../entities/bullet.h"

#include "projectile_manager.h"

class InputManager
{
    private:
        //Dependency injection
        ProjectileManager* m_bulletManager = nullptr; 

    public:
        //Functions
        void SetBulletManager(ProjectileManager* mgr) { m_bulletManager = mgr; }

        void Movement(Player* player);
        void Attack(Player* player, sf::Texture* bullet_texture);

        void Update(Player* player, sf::Texture* bullet_texture);
};

#endif //INPUT_MANAGER_H