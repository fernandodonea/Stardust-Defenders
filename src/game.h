#ifndef GAME_H
#define GAME_H

#include "player.h"



namespace Game_Engine
{



class Game
{
    private:
        sf::RenderWindow* window;

        //Player
        Player* player;

        //Private Functions
        void _InitWindow();
        void _InitPlayer();

    public:
        //Constructors and destructors
        Game();
        virtual ~Game();

        //Functions
        void Run(); 

        void Update();
        void Render();

};



}// namespace Game_Engine

#endif // GAME_H