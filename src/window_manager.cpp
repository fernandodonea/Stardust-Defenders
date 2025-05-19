#include "../include/window_manager.h" 

/*
--------------------------------
    Constructor and destructor
--------------------------------
*/
WindowManger::WindowManger()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1024,728),"Stardust Defenders",
    sf::Style::Close | sf::Style::Titlebar);

    this->window->setFramerateLimit(60);
}
WindowManger::~WindowManger()
{
    delete this->window;
}

/*
------------
    Getter
------------
*/

sf::RenderWindow* WindowManger::GetWindow()
{
    return this->window;
}


/*
----------------
    Functions
----------------
*/
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