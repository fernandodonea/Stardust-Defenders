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

        //Private Functions
        void _InitTexture();
        void _InitSprite();



    public:
        //Constructor and destructor
        Player();
        virtual ~Player();

        //Functions
        void Move(const float dir_x, const float dir_y);

        void Update();
        void Render(sf::RenderTarget& target); 



};



#endif // PLAYER_H


