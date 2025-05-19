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
#include "player_manager.h"
#include "enemy_manager.h"
#include "bullet_manager.h"


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

        //Player 
        PlayerManager *m_player_manager;

        //Enemy
        EnemyManager *m_enemy_manager;

        //Bullet 
        BulletManager *m_bullet_manager;




        //World 
        sf::Texture world_background_texture;
        sf::Sprite world_background;

        //Systems
        int points;






         
        //Private Functions

        void _InitWorld();
        void _InitSystems();


    public:
        //Constructors and destructors
        Game();
        virtual ~Game();

        //Functions
        void Run(); 

        void UpdateInput();

        void UpdateWorld();

        void UpdateEnemies();
        void UpdateCombat();
        void Update();
        
        void RenderWord();
        void Render();

};



}// namespace Game_Engine

#endif // GAME_H