#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy: public Entity
{
    protected:  
        int type;
        
        int hp;
        int hp_max;

        int damage;
        int points;

        //Private functions

    public:
        //Constructor and Destructor
        Enemy();
        virtual ~Enemy();

        //Accesors
        const int& GetType() const;
        const int& GetPoints() const;
        const int& GetDamage() const;
        
        //Functions
        void Update() override;
};






#endif // ENEMY_H