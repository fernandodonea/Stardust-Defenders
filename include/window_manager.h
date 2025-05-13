#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class WindowManger
{
    private:
        sf::RenderWindow* window;

        //Private functions
        void _InitWindow();
    public:
        //Constructor and destructor
        WindowManger();
        ~WindowManger();

        //Functions
        sf::RenderWindow* GetWindow();
        void PollEvents();
};

#endif //WINDOW_MANAGER_H