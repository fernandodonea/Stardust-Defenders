/*
@class WindowManager
@brief Manages the game window and window-related events.

    WindowManager is responsible for creating and maintaining the main game window.

    It provides access to the window for rendering, handles window events,
    and manages window properties like size and title.
    
    WindowManager centralizes all window-related logic.
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