#ifndef PLAYER_H
#define PLAYER_H


#include "entity.h"
#include "../interfaces/damageable.h"

class Player: public Entity, public Damageable
{
    protected:
        float m_attack_cooldown;
        float m_attack_cooldown_max; 

        int m_hp;
        int m_hp_max;

        //Protected functions
        void _InitVariables() override;

    public:
        //Constructor and destructor
        Player()=default;
        Player(sf::Texture* texture);
        virtual ~Player()=default;

        //Getter
        const int& GetHp() const;
        const int& GetHpMax() const ; 


        //Functions
        std::string ToString() const override;
        void LoseHp(int value) override;
        
        const bool CanAttack();
        void UpdateAttack();


        void Update() override;
};



#endif // PLAYER_H


