#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include "../interfaces/damageable.h"

class Enemy: public Entity, public Damageable
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
        std::string ToString() const override;

        void LoseHp(int value) override;

        void Update() override;
};






#endif // ENEMY_H