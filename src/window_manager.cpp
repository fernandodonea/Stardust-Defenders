#include "../include/window_manager.h" 

//Private functions
void WindowManger::_InitWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1024,728),"Stardust Defenders",
    sf::Style::Close | sf::Style::Titlebar);

    this->window->setFramerateLimit(60);
}


WindowManger::WindowManger()
{
    this->_InitWindow();
}
WindowManger::~WindowManger()
{
    delete this->window;
}

sf::RenderWindow* WindowManger::GetWindow()
{
    return this->window;
}

void WindowManger::PollEvents()
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