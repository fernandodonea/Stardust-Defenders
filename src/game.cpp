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



//Constructors and destructors
Game::Game()
{
    this->_InitWindow();

}

Game::~Game()
{
    delete this->window;

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

}


void Game::Render()
{
    this->window->clear();

    //Draw all the stuff

    this->window->display();

}



}//namespace Game_Engine