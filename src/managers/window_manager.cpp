#include "../include/managers/window_manager.h" 

/*
--------------------------------
    Constructor and destructor
--------------------------------
*/
WindowManger::WindowManger()
{
    this->m_window = new sf::RenderWindow(sf::VideoMode(1024,728),"Stardust Defenders",
    sf::Style::Close | sf::Style::Titlebar);

    this->m_window->setFramerateLimit(60);
}
WindowManger::~WindowManger()
{
    delete this->m_window;
}



/*
------------
    Getter
------------
*/

sf::RenderWindow* WindowManger::GetWindow()
{
    return this->m_window;
}


/*
----------------
    Functions
----------------
*/

// Poll events from the window
void WindowManger::PollEvents()
{
    sf::Event ev;
    while(this->m_window->pollEvent(ev))
    {
        if(ev.Event::type==sf::Event::Closed)
            this->m_window->close();
        if(ev.Event::KeyPressed && ev.Event::key.code==sf::Keyboard::Escape)
            this->m_window->close();
    }
}