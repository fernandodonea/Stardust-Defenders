#ifndef PLAYER_H
#define PLAYER_H


#include "entity.h"

class Player: public Entity
{
    protected:
        float m_attack_cooldown;
        float m_attack_cooldown_max; 

        int m_hp;
        int m_hp_max;

        void _InitVariables() override;

    public:
        //Constructor and destructor
        Player()=default;
        Player(sf::Texture* texture);
        virtual ~Player()=default;

        //Getter
        const int& GetHp() const;
        const int& GetHpMax() const ; 

        //Setter
        void SetHp(const int hp);
        void LoseHp(const int value);


        //Functions
        const bool CanAttack();
        void UpdateAttack();

        void Update() override;
};



#endif // PLAYER_H


