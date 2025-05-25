#ifndef ALIEN_H
#define ALIEN_H

#include "enemy.h"
#include "constants/constants_enemy.h"



enum class AlienPos { Left, Center, Right };
enum class MoveState {Idle, Moving};

class Alien : public Enemy
{
    private:
        AlienPos m_currentPos = AlienPos::Center;

        MoveState m_state = MoveState::Idle;

        float m_targetX = 0.f;

        int m_idleFrames = 0;
        int m_idleFramesMax = 180; // ~1 second at 60 FPSd => 3 seconds total

        //Private Function
        void _InitVariables() override;

    public:
        //Constructor and Destructor
        Alien();
        Alien(sf::Texture* texture,float pos_x, float pos_y);
        virtual ~Alien();

        //Functions
        void DecideNextMove();
        void MoveToTarget();

        void Update() override;

};

#endif //ALIEN_H