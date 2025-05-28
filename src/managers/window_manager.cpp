#include "../include/managers/window_manager.h" 

#include "../include/constants/constants_game.h"

/*
--------------------------------
    Constructor and destructor
--------------------------------
*/
WindowManager::WindowManager()
{
    this->m_window = new sf::RenderWindow(
        sf::VideoMode(
            Const_Window::window_width,
            Const_Window::window_height),
        Const_Window::window_title,
    sf::Style::Close | sf::Style::Titlebar);

    this->m_window->setFramerateLimit(60);
}
WindowManager::~WindowManager()
{
    delete this->m_window;
}



/*
------------
    Getter
------------
*/

sf::RenderWindow* WindowManager::GetWindow()
{
    return this->m_window;
}


/*
----------------
    Functions
----------------
*/

// Poll events from the window
void WindowManager::PollEvents()
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