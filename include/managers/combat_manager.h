/*
CombatManager handles the combat system and collision detection.

Responsible for checking collisions between player and enemies, bullets and enemies, and lasers and player.
Manages damage application, enemy deletion, and score updates.
*/


#ifndef COMBAT_MANAGER_H
#define COMBAT_MANAGER_H

#include "../entities/player.h"
#include "../entities/asteroid.h"
#include "../entities/bullet.h"

#include "world_manager.h"

class CombatManager
{
    public:
        //Functions
        void HandleEnemyPlayerCollision(
            Player *player,
            std::vector<Enemy*>& enemies
        );

        void HandleLaserPlayerCollision(
            Player *player,
            std::vector<Projectile*>& lasers
        );

        void HandleBulletEnemyCollisions(
            std::vector<Projectile*>& projectiles,
            std::vector<Enemy*>& enemies,
            WorldManager *world
        );

        void Update(
            Player *player,
            std::vector<Enemy*>& enemies,
            std::vector<Projectile*>& projectiles,
            std::vector<Projectile*>& lasers,
             WorldManager *world
        );

};

#endif //COMBAT_MANAGER_H