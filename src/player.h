#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Player
{
    private:
        sf::Sprite sprite;
        sf::Texture texture;

        //Private Functions
        void _InitTexture();
        void _InitSprite();



    public:
        //Constructor and destructor
        Player();
        virtual ~Player();

        //Functions
        void Update();
        void Render(sf::RenderTarget& target); 



};



#endif // PLAYER_H


