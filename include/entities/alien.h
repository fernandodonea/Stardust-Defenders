#ifndef ALIEN_H
#define ALIEN_H

#include "enemy.h"
#include "laser.h"
#include "constants/constants_enemy.h"

#include "../managers/bullet_manager.h"


enum class AlienPos { Left, Center, Right };
enum class MoveState {Idle, Moving};

class Alien : public Enemy
{
    private:
        AlienPos m_currentPos = AlienPos::Center;
        MoveState m_state = MoveState::Idle;

        float m_target_x = 0.f;

        int m_idle_frames = 0;
        int m_idleframes_max = 180; //1 second at 60 FPSd => 3 seconds total

        //Dependency injection
        ProjectileManager* m_projectile_manager = nullptr;

        //Private Function
        void _InitVariables() override;

    public:
        //Constructor and Destructor
        Alien()=default;
        Alien(sf::Texture* texture,float pos_x, float pos_y);
        virtual ~Alien()=default;

        //Setter
        void SetProjectileManager(ProjectileManager* mgr) { m_projectile_manager = mgr; }
        
        //Functions
        void DecideNextMove();
        void MoveToTarget();

        void Attack(sf::Texture* laser_texture);

        void Update(sf::Texture* laser_texture);

};

#endif //ALIEN_H