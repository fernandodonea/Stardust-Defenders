#ifndef BULLET_H
#define BULLET_H


#include "projectile.h"

#include <iostream>

class Bullet: public Projectile
{
    private:
        //Private functions
        void _InitVariables() override;


    public:
        //Constructor and destructor
        Bullet()=default;
        Bullet(sf::Texture* texture,float pos_x, float pos_y);
        virtual ~Bullet()=default;
};




#endif // BULLET_H