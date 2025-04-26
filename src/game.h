#ifndef GAME_H
#define GAME_H

#include<map>
#include <vector>

#include "player.h"
#include "bullet.h"


namespace Game_Engine
{



class Game
{
    private:
        //Window
        sf::RenderWindow* window;

        //Resources 
        std::map<std::string, sf::Texture*> textures;
        std::vector<Bullet*> bullets;

        //Player
        Player* player;

        //Private Functions
        void _InitWindow();
        void _InitTextures();
        void _InitPlayer();

    public:
        //Constructors and destructors
        Game();
        virtual ~Game();

        //Functions
        void Run(); 

        void UpdatePollEvents();
        void UpdateInput();
        void UpdateBullets();
        void Update();
        
        void Render();

};



}// namespace Game_Engine

#endif // GAME_H