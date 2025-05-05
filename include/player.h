#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>

class Player
{
    private:
        sf::Sprite sprite;
        sf::Texture texture;

        float movement_speed;

        float attack_cooldown;
        float attack_cooldown_max; 

        int hp;
        int hp_max;


        //Private Functions
        void _InitVariables();
        void _InitTexture();
        void _InitSprite();


    public:
        //Constructor and destructor
        Player();
        virtual ~Player();

        //Accesors
        const sf::Vector2f& GetPosition() const;
        const sf::FloatRect GetBounds() const;

        const int& GetHp() const;
        const int& GetHpMax() const ; 

        //Modifiers
        void SetPosition(const sf::Vector2f pos);
        void SetPosition(const float x, const float y);

        void SetHp(const int hp);
        void LooseHp(const int hp);



        //Functions
        void Move(const float dir_x, const float dir_y);

        const bool CanAttack();
        void UpdateAttack();
        

        void Update();
        void Render(sf::RenderTarget& target); 



};



#endif // PLAYER_H


