#ifndef GAME_H
#define GAME_H

#include <map>
#include <vector>
#include <string>
#include <sstream>


#include "player.h"
#include "bullet.h"
#include "asteroid.h"

#include "window_manager.h"
#include "resource_manager.h"
#include "gui_manager.h"


namespace Game_Engine
{



class Game
{
    private:
        //Core
        WindowManger* m_window_manager;
        ResourceManager* m_resource_manager;
        
        //GUI
        GuiManager* m_gui_manager;
        
        //Resources 
        std::vector<Bullet*> m_bullets;


        //World 
        sf::Texture world_background_texture;
        sf::Sprite world_background;

        //Systems
        int points;


        //Player
        Player* m_player;


        //Enemies
        float spawn_timer;
        float spawn_timer_max;
        std::vector<Asteroid*> m_enemies;

         
        //Private Functions

        void _InitWorld();
        void _InitSystems();

        void _InitPlayer();
        void _InitEnemies();

    public:
        //Constructors and destructors
        Game();
        virtual ~Game();

        //Functions
        void Run(); 

        void UpdateInput();

        void UpdateWorld();
        void UpdateCollision();
        void UpdateBullets();
        void UpdateEnemies();
        void UpdateCombat();
        void Update();
        
        void RenderWord();
        void Render();

};



}// namespace Game_Engine

#endif // GAME_H