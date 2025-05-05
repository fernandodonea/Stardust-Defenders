#ifndef GAME_H
#define GAME_H

#include <map>
#include <vector>
#include <string>
#include <sstream>

#include "player.h"
#include "bullet.h"
#include "enemy.h"


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

        //GUI
        sf::Font font;
        sf::Text point_text;

        sf::Text game_over_text;

        //World 
        sf::Texture world_background_texture;
        sf::Sprite world_background;

        //Systems
        unsigned points;


        //Player
        Player* player;

        //Player GUI
        sf::RectangleShape player_hp_bar;
        sf::RectangleShape player_hp_bar_back;

        //Enemies
        float spawn_timer;
        float spawn_timer_max;
        std::vector<Enemy*> enemies;

         
        //Private Functions
        void _InitWindow();
        void _InitTextures();
        void _InitGUI();

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

        void UpdatePollEvents();
        void UpdateInput();
        void UpdateGUI();
        void UpdateWorld();
        void UpdateCollision();
        void UpdateBullets();
        void UpdateEnemies();
        void UpdateCombat();
        void Update();
        
        void RenderGUI();
        void RenderWord();
        void Render();

};



}// namespace Game_Engine

#endif // GAME_H