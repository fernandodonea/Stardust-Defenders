#include "../include/game.h"

namespace Game_Engine
{




/*
-------------------------------
    Constructor and destructor
------------------------------
*/
Game::Game()
{
    this->m_window_manager = new WindowManger(); 

    this->m_resource_manager = new ResourceManager(); 

    this->m_gui_manager = new GuiManager(
        m_resource_manager->GetFont(),
        m_window_manager->GetWindow()
    ); 

    this->m_player_manager = new PlayerManager(m_resource_manager->GetTexture("PLAYER"));

    this->m_input_manager = new InputManager();

    this->m_enemy_manager = new EnemyManager(
        m_resource_manager->GetTexture("ASTEROID_NORMAL"),
        m_resource_manager->GetTexture("ASTEROID_FAST"),
        m_resource_manager->GetTexture("ASTEROID_TANK"),
        m_resource_manager->GetTexture("ALIEN")
    );

    this->m_projectile_manager = new ProjectileManager();

    this->m_combat_manager = new CombatManager();

    this->m_world_manager = new WorldManager(m_resource_manager->GetTexture("BACKGROUND"));


    //Dependency injection
    this->m_input_manager->SetBulletManager(this->m_projectile_manager);

    this->m_enemy_manager->SetProjectileManagerForAliens(this->m_projectile_manager);

   
}

Game::~Game()
{
    delete this->m_window_manager;

    delete this->m_resource_manager;

    delete this->m_gui_manager;

    delete this->m_player_manager;

    delete this->m_input_manager;

    delete this->m_enemy_manager;

    delete this->m_projectile_manager;

    delete this->m_combat_manager;

    delete this->m_world_manager;

} 


 
/*
---------------
    Functions
---------------
*/
void Game::Run()
{
    while(this->m_window_manager->GetWindow()->isOpen())
    {
        this->m_window_manager->PollEvents();
        
        if(this->m_player_manager->GetPlayer()->GetHp()>0)
            this->Update();
        this->Render(); 
    }

}


void Game::Update()
{
    this->m_input_manager->Update(
        this->m_player_manager->GetPlayer(),
        this->m_resource_manager->GetTexture("BULLET")
    );

  
    this->m_player_manager->Update(
        this->m_window_manager->GetWindow()
    );

    this->m_projectile_manager->Update();

    this->m_enemy_manager->Update(
        this->m_window_manager->GetWindow(),
        this->m_resource_manager->GetTexture("LASER")
    );

    this->m_combat_manager->Update(
        m_player_manager->GetPlayer(),
        m_enemy_manager->GetEnemies(),
        m_projectile_manager->GetBullets(),
        m_projectile_manager->GetLasers(),
        m_world_manager
    );
    

    m_gui_manager->Update(
        this->m_world_manager->GetPoints(),
        this->m_player_manager->GetPlayer()->GetHp(),
        this->m_player_manager->GetPlayer()->GetHpMax()
    );

}



void Game::Render()
{
    //Clear the screen
    this->m_window_manager->GetWindow()->clear();



    //Draw world
    this->m_world_manager->Render(*this->m_window_manager->GetWindow());

    //Render de player
    this->m_player_manager->GetPlayer()->Render(*this->m_window_manager->GetWindow());

    //Render the bullets
    for(auto *bullet: this->m_projectile_manager->GetBullets())
    {
        bullet->Render(*this->m_window_manager->GetWindow());
    }

    //Render the lasers
    for(auto *laser: this->m_projectile_manager->GetLasers())
    {
        laser->Render(*this->m_window_manager->GetWindow());
    }

    //Render the enemies
    for(auto *asteroid: this->m_enemy_manager->GetEnemies())
    {
        asteroid->Render(*this->m_window_manager->GetWindow());
    }

    //Render Gui
    this->m_gui_manager->Render(*this->m_window_manager->GetWindow());

    //Game Over Screen
    if(this->m_player_manager->GetPlayer()->GetHp()<=0)
    {
        this->m_gui_manager->GameOver(*this->m_window_manager->GetWindow());
    }
   

    
    this->m_window_manager->GetWindow()->display();
}



}//namespace Game_Engine