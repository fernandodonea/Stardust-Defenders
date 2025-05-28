/*
    WindowManager manages the game window and window-related events.
 
    Responsible for creating and maintaining the main game window, 
    handling window events, and managing window properties.
*/



#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class WindowManager
{
    private:
        sf::RenderWindow* m_window;

    public:
        //Constructor and destructor
        WindowManager();
        ~WindowManager();

        //Getter
        sf::RenderWindow* GetWindow();

        //Functions
        void PollEvents();
};

#endif //WINDOW_MANAGER_H