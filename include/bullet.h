#ifndef BULLET_H
#define BULLET_H


#include "projectile.h"



class Bullet: public Projectile
{
    private:
        void _InitVariables() override;
        void _InitTexture() override;
        void _InitSprite() override;


    public:
        //Constructor and destructor
        Bullet();
        Bullet(float pos_x, float pos_y);
        virtual ~Bullet();
};




#endif // BULLET_H