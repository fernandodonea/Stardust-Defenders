#ifndef ASTEROID_H
#define ASTEROID_H

#include "enemy.h"
#include "constants/constants_asteroid.h"

class Asteroid: public Enemy
{
    private:
        //Private functions
        void _InitVariables() override;


    public:
        //Constructor and Destructor
        Asteroid();
        Asteroid(int type, sf::Texture* texture,float pos_x, float pos_y);
        virtual ~Asteroid();

        //Accesors

        //Functions
        void Update() override;
  
};



#endif // ENEMY_H