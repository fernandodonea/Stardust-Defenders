#ifndef ASTEROID_H
#define ASTEROID_H

#include "enemy.h"
#include "constants/constants_enemy.h"

class Asteroid: public Enemy
{
    private:
        static int m_asteroids_destroyed;

        //Private functions
        void _InitVariables() override;

    public:
        //Constructor and Destructor
        Asteroid()=default;
        Asteroid(int type, sf::Texture* texture,float pos_x, float pos_y);
        virtual ~Asteroid()=default;

        //Getter
        static int GetAsteroidsDestroyed();

        //Setter
        static void IncrementAsteroidsDestroyed();
 
        //Functions
        void Update() override;
};



#endif // ENEMY_H