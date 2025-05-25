#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class GuiManager
{
    private:
        sf::Text m_point_text;
        sf::Text m_game_over_text;

        //Player GUI
        sf::RectangleShape m_player_hp_bar;
        sf::RectangleShape m_player_hp_bar_back;

        void _InitPoints(sf::Font &font);
        void _InitGameOver(sf::Font &font,sf::RenderWindow* window);
        void _InitHealthBar();

    public:
        //Constructors and destructor
        GuiManager()=default;
        GuiManager(sf::Font &font,sf::RenderWindow* window);
        ~GuiManager()=default;

        //Functions
        void Update(int points, int health, int health_max);
        void Render(sf::RenderTarget& target);
        void GameOver(sf::RenderTarget& target);
};



#endif // GUI_MANAGER_H