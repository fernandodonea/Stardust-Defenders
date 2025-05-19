#include "../include/game.h"

namespace Game_Engine
{






//Constructors and destructors
Game::Game()
{
    this->m_window_manager = new WindowManger(); // Initialize the window manager

    this->m_resource_manager = new ResourceManager(); // Initialize the resource manager

    this->m_gui_manager = new GuiManager(
        m_resource_manager->GetFont(),
        m_window_manager->GetWindow()
    ); // Initialize GUI

    this->m_player_manager = new PlayerManager();

    this->m_enemy_manager = new EnemyManager();

    this->m_bullet_manager = new BulletManager();

    this->m_combat_manager = new CombatManager();

    this->m_world_manager = new WorldManager();
}

Game::~Game()
{
    delete this->m_window_manager;

    delete this->m_resource_manager;

    delete this->m_gui_manager;

    delete this->m_player_manager;

    delete this->m_enemy_manager;

    delete this->m_bullet_manager;

    delete this->m_combat_manager;

    delete this->m_world_manager;

} 


 
//Functions
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



void Game::UpdateInput()
{
    //Move player
    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->m_player_manager->GetPlayer()->Move(-1.f,0.f);
    //Right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->m_player_manager->GetPlayer()->Move(1.f,0.f);
    //Up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->m_player_manager->GetPlayer()->Move(0.f,-1.f);
    //Down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->m_player_manager->GetPlayer()->Move(0.f,1.f);

    //Shoot Bullets
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->m_player_manager->GetPlayer()->CanAttack())
    {
        this->m_bullet_manager->GetBullets().push_back(
            new Bullet(
                this->m_player_manager->GetPlayer()->GetPosition().x + this->m_player_manager->GetPlayer()->GetBounds().width/2.f-12.f,
                this->m_player_manager->GetPlayer()->GetPosition().y
            )
        );
    }
}










void Game::Update()
{
    this->UpdateInput();

  
    this->m_player_manager->Update(
        this->m_window_manager->GetWindow()
    );

    this->m_bullet_manager->Update();

    this->m_enemy_manager->Update(
        this->m_window_manager->GetWindow()
    );

    this->m_combat_manager->Update(
        m_player_manager->GetPlayer(),
        m_enemy_manager->GetAsteroids(),
        m_bullet_manager->GetBullets(),
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
    for(auto *bullet: this->m_bullet_manager->GetBullets())
    {
        bullet->Render(*this->m_window_manager->GetWindow());
    }

    //Render the enemies
    for(auto *enemy: this->m_enemy_manager->GetAsteroids())
    {
        enemy->Render(*this->m_window_manager->GetWindow());
    }

    //Render Gui
    this->m_gui_manager->Render(*this->m_window_manager->GetWindow());

    //Game Over Screen
    if(this->m_player_manager->GetPlayer()->GetHp()<=0)
        this->m_gui_manager->GameOver(*this->m_window_manager->GetWindow());

      
    this->m_window_manager->GetWindow()->display();
}



}//namespace Game_Engine