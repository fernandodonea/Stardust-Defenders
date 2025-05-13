#ifndef PLAYER_H
#define PLAYER_H


#include "entity.h"

class Player: public Entity
{
    protected:
        float attack_cooldown;
        float attack_cooldown_max; 

        int hp;
        int hp_max;

        void _InitVariables() override;
        void _InitTexture() override;
        void _InitSprite() override;

    public:
        //Constructor and destructor
        Player();
        virtual ~Player();

        //Accesors
        const int& GetHp() const;
        const int& GetHpMax() const ; 

        //Modifiers
        void SetHp(const int hp);
        void LoseHp(const int value);


        //Functions
        const bool CanAttack();
        void UpdateAttack();

        void Update() override;
};



#endif // PLAYER_H


