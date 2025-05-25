#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy: public Entity
{
    protected:  
        int m_type;
        
        int m_hp;
        int m_hp_max;

        int m_damage;
        int m_points;

        float m_size;


    public:
        //Constructor and Destructor
        Enemy()=default;
        virtual ~Enemy()=default;

        //Getters
        const int& GetType() const;
        const int& GetHp() const;
        const int& GetPoints() const;
        const int& GetDamage() const;
        
        //Functions
        void LoseHp(const int value);

        void Update() override;
};






#endif // ENEMY_H