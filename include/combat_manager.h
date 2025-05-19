#ifndef COMBAT_MANAGER_H
#define COMBAT_MANAGER_H

#include "player.h"
#include "asteroid.h"
#include "bullet.h"
#include "world_manager.h"

class CombatManager
{
    public:
        void HandleEnemyPlayerCollision(
            Player *player,
            std::vector<Asteroid*>& asteroids
        );
        void HandleBulletEnemyCollisions(
            std::vector<Bullet*>& bullets,
            std::vector<Asteroid*>& asteroids,
            WorldManager *world
        );
        void Update(
            Player *player,
            std::vector<Asteroid*>& asteroids,
            std::vector<Bullet*>& bullets,
             WorldManager *world
        );

};

#endif //COMBAT_MANAGER_H