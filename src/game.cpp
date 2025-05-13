#include "../include/game.h"

namespace Game_Engine
{



//Private Functions
 


void Game::_InitWorld()
{
    //Load background
    if(!this->world_background_texture.loadFromFile("resources/textures/starry_background.png"))
        std::cout<<"ERROR::GAME::_INITWORLD: Failed to load background"<<"\n";

    this->world_background.setTexture(this->world_background_texture);
}

void Game::_InitSystems()
{
    this->points=0;
}

void Game::_InitPlayer()
{
    this->m_player = new Player();
}

void Game::_InitEnemies()
{
    this->spawn_timer_max=50.f;
    this->spawn_timer=this->spawn_timer_max;
}



//Constructors and destructors
Game::Game()
{
    this->m_window_manager = new WindowManger(); // Initialize the window manager

    this->m_resource_manager = new ResourceManager(); // Initialize the resource manager

    this->m_gui_manager = new GuiManager(
        m_resource_manager->GetFont(),
        m_window_manager->GetWindow()
    ); // Initialize GUI

    this->_InitWorld();
    this->_InitSystems();
    this->_InitPlayer();
    this->_InitEnemies();
}

Game::~Game()
{
    delete this->m_window_manager;

    delete this->m_resource_manager;

    delete this->m_gui_manager;



    delete this->m_player;


    // Delete any bullets left
    for(auto *i: this->m_bullets)
    {
        delete i;
    }

    // Delete enemies
    for(auto *i: this->m_enemies)
    {
        delete i;
    }
} 


 
//Functions
void Game::Run()
{
    while(this->m_window_manager->GetWindow()->isOpen())
    {
        this->m_window_manager->PollEvents();
        
        if(this->m_player->GetHp()>0)
            this->Update();
        this->Render(); 
    }

}



void Game::UpdateInput()
{
    //Move player
    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->m_player->Move(-1.f,0.f);
    //Right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->m_player->Move(1.f,0.f);
    //Up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->m_player->Move(0.f,-1.f);
    //Down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->m_player->Move(0.f,1.f);

    //Shoot Bullets
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->m_player->CanAttack())
    {
        this->m_bullets.push_back(
            new Bullet(
                this->m_player->GetPosition().x + this->m_player->GetBounds().width/2.f-12.f,
                this->m_player->GetPosition().y
            )
        );
    }
}




void Game::UpdateWorld()
{

}
void Game::UpdateCollision()
{
    //Left world collision
    if(this->m_player->GetBounds().left<0.f)
    {
        this->m_player->SetPosition(
            0.f,
            this->m_player->GetBounds().top
        );
    }
    //Right world collision
    else if(this->m_player->GetBounds().left+this->m_player->GetBounds().width > this->m_window_manager->GetWindow()->getSize().x)
    {
        this->m_player->SetPosition(
            this->m_window_manager->GetWindow()->getSize().x - this->m_player->GetBounds().width,
            this->m_player->GetBounds().top
        );
    }
    //Top world collision
    if(this->m_player->GetBounds().top<0.f)
    {
        this->m_player->SetPosition(
            this->m_player->GetBounds().left,
            0.f
        );
    }
    //Bottom world collision
    else if(this->m_player->GetBounds().top+this->m_player->GetBounds().height > this->m_window_manager->GetWindow()->getSize().y)
    {
        this->m_player->SetPosition(
            this->m_player->GetBounds().left,
            this->m_window_manager->GetWindow()->getSize().y - this->m_player->GetBounds().height
        );
    }
}


void Game::UpdateBullets()
{
    unsigned counter=0;

    for(auto *bullet: this->m_bullets)
    {
        bullet->Update();

        // Bullet culling (top of the screen)
        if(bullet->GetBounds().top + bullet->GetBounds().height < 0.f)
        {
            //Delete bullet
            delete this->m_bullets.at(counter);
            this->m_bullets.erase(this->m_bullets.begin()+counter);
            
        }

        ++counter;
    }
}
void Game::UpdateEnemies()
{
    //Spawning
    this->spawn_timer+=0.5f;
    if(this->spawn_timer >= this->spawn_timer_max)
    {
        this->m_enemies.push_back(new Asteroid(rand()%this->m_window_manager->GetWindow()->getSize().x-80.f, -100.f));
        this->spawn_timer=0.f;
    }

    //Update 
    unsigned counter=0; 
    for(auto *enemy: this->m_enemies)
    {
        enemy->Update();

        // Enemy culling (Bottom of the screen)
        if(enemy->GetBounds().top > this->m_window_manager->GetWindow()->getSize().y)
        {
            //Delete Enemy
            delete this->m_enemies.at(counter);
            this->m_enemies.erase(this->m_enemies.begin()+counter);
             
        }
        //Enemy player collision 
        else if(enemy->GetBounds().intersects(this->m_player->GetBounds()))
        {
            //take damge
            this->m_player->LoseHp(this->m_enemies.at(counter)->GetDamage());

            delete this->m_enemies.at(counter);
            this->m_enemies.erase(this->m_enemies.begin()+counter);
            
        }

        ++counter;
    }
}

void Game::UpdateCombat()
{
    for(int i=0; i<this->m_enemies.size(); ++i)
    { 
        bool enemy_deleted=false;

        for(size_t k=0; k<this->m_bullets.size() && enemy_deleted==false; ++k)
        {
            if(this->m_enemies[i]->GetBounds().intersects(this->m_bullets[k]->GetBounds()))
            {
                //Enemy take damage
                this->m_enemies[i]->LoseHp(this->m_bullets[k]->GetDamage());

                if(m_enemies[i]->GetHp()==0)
                {
                    //Increase points
                    this->points+=this->m_enemies[i]->GetPoints();

                    //Delete Enemy
                    delete this->m_enemies[i];
                    this->m_enemies.erase(this->m_enemies.begin() + i);

                    enemy_deleted=true;
                }


                //Delete Bullet
                delete this->m_bullets[k];
                this->m_bullets.erase(this->m_bullets.begin() + k); 
                
            }
        }
    }
}

void Game::Update()
{
    this->UpdateInput();

    this->UpdateCollision();


    this->m_player->Update();

    this->UpdateBullets();
    this->UpdateEnemies();
    this->UpdateCombat();

    m_gui_manager->Update(
        this->points,
        this->m_player->GetHp(),
        this->m_player->GetHpMax()
    );

    this->UpdateWorld();
}




void Game::RenderWord()
{
    this->m_window_manager->GetWindow()->draw(this->world_background);
}

void Game::Render()
{
    //Clear the screen
    this->m_window_manager->GetWindow()->clear();

    //Draw world
    this->RenderWord();


    //Render de player
    this->m_player->Render(*this->m_window_manager->GetWindow());

    //Render the bullets
    for(auto *bullet: this->m_bullets)
    {
        bullet->Render(*this->m_window_manager->GetWindow());
    }

    //Render the enemies
    for(auto *enemy: this->m_enemies)
    {
        enemy->Render(*this->m_window_manager->GetWindow());
    }

    //Render Gui
    this->m_gui_manager->Render(*this->m_window_manager->GetWindow());

    //Game Over Screen
    if(this->m_player->GetHp()<=0)
        this->m_gui_manager->GameOver(*this->m_window_manager->GetWindow());


        
    this->m_window_manager->GetWindow()->display();
}



}//namespace Game_Engine