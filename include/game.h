#ifndef GAME_H
#define GAME_H

#include <map>
#include <vector>
#include <string>
#include <sstream>


#include "./managers/window_manager.h"
#include "./managers/resource_manager.h"
#include "./managers/gui_manager.h"
#include "./managers/player_manager.h"
#include "./managers/input_manager.h"
#include "./managers/enemy_manager.h"
#include "./managers/projectile_manager.h"
#include "./managers/combat_manager.h"
#include "./managers/world_manager.h"


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

        //Input
        InputManager *m_input_manager;

        //Enemy
        EnemyManager *m_enemy_manager;

        //Bullet 
        ProjectileManager *m_projectile_manager;

        //Combat
        CombatManager *m_combat_manager;

        //World 
        WorldManager *m_world_manager;


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