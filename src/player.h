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

        //Functions
        void Move(const float dir_x, const float dir_y);

        const bool CanAttack();
        void UpdateAttack();
        

        void Update();
        void Render(sf::RenderTarget& target); 



};



#endif // PLAYER_H


