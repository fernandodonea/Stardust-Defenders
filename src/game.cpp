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

    this->m_player_manager = new PlayerManager(this->m_window_manager->GetWindow());

    this->m_enemy_manager = new EnemyManager(this->m_window_manager->GetWindow());

    this->m_bullet_manager = new BulletManager(this->m_window_manager->GetWindow());

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








void Game::UpdateEnemies()
{


    //Update 
    unsigned counter=0; 
    for(auto *enemy: this->m_enemy_manager->GetAsteroids())
    {

        //Enemy player collision 
        if(enemy->GetBounds().intersects(this->m_player_manager->GetPlayer()->GetBounds()))
        {
            //take damge
            this->m_player_manager->GetPlayer()->LoseHp(this->m_enemy_manager->GetAsteroids().at(counter)->GetDamage());

            delete this->m_enemy_manager->GetAsteroids().at(counter);
            this->m_enemy_manager->GetAsteroids().erase(this->m_enemy_manager->GetAsteroids().begin()+counter); 
        }

        ++counter;
    }
}

void Game::UpdateCombat()
{
    for(int i=0; i<this->m_enemy_manager->GetAsteroids().size(); ++i)
    { 
        bool enemy_deleted=false;

        for(size_t k=0; k<this->m_bullet_manager->GetBullets().size() && enemy_deleted==false; ++k)
        {
            if(this->m_enemy_manager->GetAsteroids()[i]->GetBounds().intersects(this->m_bullet_manager->GetBullets()[k]->GetBounds()))
            {
                //Enemy take damage
                this->m_enemy_manager->GetAsteroids()[i]->LoseHp(this->m_bullet_manager->GetBullets()[k]->GetDamage());

                if(m_enemy_manager->GetAsteroids()[i]->GetHp()==0)
                {
                    //Increase points
                    this->m_world_manager->AddPoints(this->m_enemy_manager->GetAsteroids()[i]->GetPoints());

                    //Delete Enemy
                    delete this->m_enemy_manager->GetAsteroids()[i];
                    this->m_enemy_manager->GetAsteroids().erase(this->m_enemy_manager->GetAsteroids().begin() + i);

                    enemy_deleted=true;
                }


                //Delete Bullet
                delete this->m_bullet_manager->GetBullets()[k];
                this->m_bullet_manager->GetBullets().erase(this->m_bullet_manager->GetBullets().begin() + k); 
                
            }
        }
    }
}

void Game::Update()
{
    this->UpdateInput();

  
    this->m_player_manager->Update();

    this->m_bullet_manager->Update();

    this->m_enemy_manager->Update();

    this->UpdateEnemies();
    this->UpdateCombat();

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