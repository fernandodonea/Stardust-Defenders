#include "game.h"

namespace Game_Engine
{



//Private Functions
void Game::_InitWindow()
{
    this->window=new sf::RenderWindow(sf::VideoMode(800,600),"Game 3",
    sf::Style::Close | sf::Style::Titlebar);

    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);

}

void Game::_InitPlayer()
{
    this->player = new Player();
}



//Constructors and destructors
Game::Game()
{
    this->_InitWindow();
    this->_InitPlayer();

}

Game::~Game()
{
    delete this->window;
    delete this->player;

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


void Game::Update()
{
    sf::Event ev;
    while(this->window->pollEvent(ev))
    {
        if(ev.Event::type==sf::Event::Closed)
            this->window->close();
        if(ev.Event::KeyPressed && ev.Event::key.code==sf::Keyboard::Escape)
            this->window->close();
    }

    //Move player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->Move(-1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->Move(1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->Move(0.f,-1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->Move(0.f,1.f);
    
    

}


void Game::Render()
{
    this->window->clear();

    //Draw all the stuff
    this->player->Render(*this->window);

    this->window->display();

}



}//namespace Game_Engine