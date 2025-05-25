#ifndef BULLET_H
#define BULLET_H


#include "projectile.h"



class Bullet: public Projectile
{
    private:
        void _InitVariables() override;
        void _InitTexture() ;
        void _InitSprite() ;

    public:
        //Constructor and destructor
        Bullet()=default;
        Bullet(float pos_x, float pos_y);
        virtual ~Bullet();
};




#endif // BULLET_H