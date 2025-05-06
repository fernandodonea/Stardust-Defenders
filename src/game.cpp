#include "../include/game.h"

namespace Game_Engine
{



//Private Functions
void Game::_InitWindow()
{
    this->window=new sf::RenderWindow(sf::VideoMode(1024,728),"Stardust Defenders",
    sf::Style::Close | sf::Style::Titlebar);

    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::_InitTextures()
{
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("resources/textures/cyan-bullet.png");
} 
 
void Game::_InitGUI()
{
    //Load font
    if(!this->font.loadFromFile("resources/fonts/Dosis.ttf"))
        std::cout<<"ERROR::GAME::_INITGUI:: Failed to load font"<<"\n";

    //Init point text
    this->point_text.setFont(this->font);
    this->point_text.setCharacterSize(36);
    this->point_text.setFillColor(sf::Color::White);
    this->point_text.setString("");
    this->point_text.setPosition(850.f,20.f);

    this->game_over_text.setFont(this->font);
    this->game_over_text.setCharacterSize(60);
    this->game_over_text.setFillColor(sf::Color::Red);
    this->game_over_text.setString("Game Over!");
    this->game_over_text.setPosition(
        this->window->getSize().x/2 - this->game_over_text.getGlobalBounds().width/2.f,
        this->window->getSize().y/2 - this->game_over_text.getGlobalBounds().height/2.f
    );

    //Init player GUI
    this->player_hp_bar.setSize(sf::Vector2f(300.f,25.f));
    this->player_hp_bar.setPosition(sf::Vector2f(20.f,15.f));
    this->player_hp_bar.setFillColor(sf::Color::Red);

    this->player_hp_bar_back=this->player_hp_bar;
    this->player_hp_bar_back.setFillColor(sf::Color(25,25,25,200));

}

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
    this->_InitWindow();
    this->_InitTextures();
    this->_InitGUI();
    this->_InitWorld();
    this->_InitSystems();
    this->_InitPlayer();
    this->_InitEnemies();
}

Game::~Game()
{
    delete this->window;
    delete this->m_player;

    //Delete texture to avoid memory leak
    for(auto &i : this->textures)
    {
        delete i.second;
    }

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
    while(this->window->isOpen())
    {
        this->UpdatePollEvents();
        
        if(this->m_player->GetHp()>0)
            this->Update();
        this->Render(); 
    }

}


void Game::UpdatePollEvents()
{
    sf::Event ev;
    while(this->window->pollEvent(ev))
    {
        if(ev.Event::type==sf::Event::Closed)
            this->window->close();
        if(ev.Event::KeyPressed && ev.Event::key.code==sf::Keyboard::Escape)
            this->window->close();
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
                this->textures["BULLET"],
                this->m_player->GetPosition().x + this->m_player->GetBounds().width/2.f-12.f,
                this->m_player->GetPosition().y,
                0.f,-1.f,8.f
            )
        );
    }
}


void Game::UpdateGUI()
{
    std::stringstream ss;

    ss<<"Points:"<<this->points<<"\n"; 

    this->point_text.setString(ss.str());


    //Update Player GUI
    float hp_percent=static_cast<float>(this->m_player->GetHp())/this->m_player->GetHpMax();
    this->player_hp_bar.setSize(sf::Vector2f(
        300.f * hp_percent,
        this->player_hp_bar.getSize().y
    ));

   

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
    else if(this->m_player->GetBounds().left+this->m_player->GetBounds().width > this->window->getSize().x)
    {
        this->m_player->SetPosition(
            this->window->getSize().x - this->m_player->GetBounds().width,
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
    else if(this->m_player->GetBounds().top+this->m_player->GetBounds().height > this->window->getSize().y)
    {
        this->m_player->SetPosition(
            this->m_player->GetBounds().left,
            this->window->getSize().y - this->m_player->GetBounds().height
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
        this->m_enemies.push_back(new Enemy(rand()%this->window->getSize().x-20.f, -100.f));
        this->spawn_timer=0.f;
    }

    //Update 
    unsigned counter=0; 
    for(auto *enemy: this->m_enemies)
    {
        enemy->Update();

        // Enemy culling (Bottom of the screen)
        if(enemy->GetBounds().top > this->window->getSize().y)
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
                //Increase points
                this->points+=this->m_enemies[i]->GetPoints();

                //Delete Enemy
                delete this->m_enemies[i];
                this->m_enemies.erase(this->m_enemies.begin() + i);

                //Delete Bullet
                delete this->m_bullets[k];
                this->m_bullets.erase(this->m_bullets.begin() + k); 

                enemy_deleted=true;
                
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

    this->UpdateGUI();

    this->UpdateWorld();
}



void Game::RenderGUI()
{
    this->window->draw(this->point_text);

    this->window->draw(this->player_hp_bar_back);
    this->window->draw(this->player_hp_bar); 

}

void Game::RenderWord()
{
    this->window->draw(this->world_background);
}

void Game::Render()
{
    this->window->clear();

    //Draw world
    this->RenderWord();


    //Render de player
    this->m_player->Render(*this->window);

    //Render the bullets
    for(auto *bullet: this->m_bullets)
    {
        bullet->Render(this->window);
    }

    //Render the enemies
    for(auto *enemy: this->m_enemies)
    {
        enemy->Render(this->window);
    }

    this->RenderGUI();

    //Game Over Screen
    if(this->m_player->GetHp()<=0)
        this->window->draw(this->game_over_text);

    this->window->display();
}



}//namespace Game_Engine