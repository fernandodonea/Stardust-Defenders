#ifndef LASER_H
#define LASER_H

#include "projectile.h"

class Laser: public Projectile
{
    private:
        //Private functions
        void _InitVariables() override;
        
    public:
        //Constructor and destructor
        Laser()=default;
        Laser(sf::Texture* texture,float pos_x, float pos_y, sf::Vector2f direction);
        virtual ~Laser()=default;

};



#endif //LASER_H