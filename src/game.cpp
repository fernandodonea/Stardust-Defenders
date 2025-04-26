#include "game.h"

namespace Game_Engine
{



//Private Functions
void Game::_InitWindow()
{
    this->window=new sf::RenderWindow(sf::VideoMode(800,600),"Stardust Defenders",
    sf::Style::Close | sf::Style::Titlebar);

    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);

}

void Game::_InitTextures()
{
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("textures/pink-bullet.png");
    
    
} 

void Game::_InitPlayer()
{
    this->player = new Player();

    
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
    this->_InitPlayer();
    this->_InitEnemies();

}

Game::~Game()
{
    delete this->window;
    delete this->player;

    //Delete texture to avoid memory leak
    for(auto &i : this->textures)
    {
        delete i.second;
    }

    // Delete any bullets left
    for(auto *i: this->bullets)
    {
        delete i;
    }

    // Delete enemies
    for(auto *i: this->enemies)
    {
        delete i;
    }


} 


 
//Functions
void Game::Run()
{
    while(this->window->isOpen())
    {
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
        this->player->Move(-1.f,0.f);
    //Right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->Move(1.f,0.f);
    //Up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->Move(0.f,-1.f);
    //Down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->Move(0.f,1.f);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->CanAttack())
    {
        this->bullets.push_back(
            new Bullet(
                this->textures["BULLET"],
                this->player->GetPosition().x + this->player->GetBounds().width/2.f,
                this->player->GetPosition().y,
                0.f,-1.f,5.f
            )
        );
    }
}

void Game::UpdateBullets()
{
    unsigned counter=0;

    for(auto *bullet: this->bullets)
    {
        bullet->Update();

        // Bullet culling (top of the screen)
        if(bullet->GetBounds().top + bullet->GetBounds().height < 0.f)
        {
            //Delete bullet
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin()+counter);
            --counter;
        }

        ++counter;
    }
}
void Game::UpdateEnemies()
{
    this->spawn_timer+=0.5f;
    if(this->spawn_timer >= this->spawn_timer_max)
    {
        this->enemies.push_back(new Enemy(rand()%this->window->getSize().x-20.f, -100.f));
        this->spawn_timer=0.f;
    }

    for(int i=0; i<this->enemies.size();++i)
    { 
        this->enemies[i]->Update();

        //Remove enemy at the bottom of the screen
        if(this->enemies[i]->GetBounds().top >= this->window->getSize().y)
        {
            this->enemies.erase(this->enemies.begin()+i);
            std::cout<<this->enemies.size()<<"\n"; 
        }
    }

}

void Game::Update()
{
    this->UpdatePollEvents();

    this->UpdateInput();

    this->player->Update();

    this->UpdateBullets();

    this->UpdateEnemies();

}


void Game::Render()
{
    this->window->clear();

    //Draw all the stuff

    //Render de player
    this->player->Render(*this->window);

    //Render the bullets
    for(auto *bullet: this->bullets)
    {
        bullet->Render(this->window);
    }

    //Render the enemies
    for(auto *enemy: this->enemies)
    {
        enemy->Render(this->window);
    }

    
    this->window->display();

}



}//namespace Game_Engine