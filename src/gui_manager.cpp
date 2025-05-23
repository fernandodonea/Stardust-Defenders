#include "../include/gui_manager.h"

#include <string>
#include <sstream>

GuiManager::GuiManager()
{

}
GuiManager::GuiManager(sf::Font &font,sf::RenderWindow* window) 
{
    _InitPoints(font);
    _InitHealthBar();
    _InitGameOver(font,window);

}
GuiManager::~GuiManager()
{

}


void GuiManager::_InitPoints(sf::Font &font)
{
    //Init POINTS text
    this->m_point_text.setFont(font);
    this->m_point_text.setCharacterSize(36);
    this->m_point_text.setFillColor(sf::Color::White);
    this->m_point_text.setString("");
    this->m_point_text.setPosition(850.f,20.f);

}
void GuiManager::_InitGameOver(sf::Font &font,sf::RenderWindow* window)
{
    //Init GAME OVER text
    this->m_game_over_text.setFont(font);
    this->m_game_over_text.setCharacterSize(60);
    this->m_game_over_text.setFillColor(sf::Color::Red);
    this->m_game_over_text.setString("Game Over!");
    this->m_game_over_text.setPosition(
        window->getSize().x/2 - this->m_game_over_text.getGlobalBounds().width/2.f,
        window->getSize().y/2 - this->m_game_over_text.getGlobalBounds().height/2.f
    );
}
void GuiManager::_InitHealthBar()
{
    //Init player GUI
    this->m_player_hp_bar.setSize(sf::Vector2f(300.f,25.f));
    this->m_player_hp_bar.setPosition(sf::Vector2f(20.f,15.f));
    this->m_player_hp_bar.setFillColor(sf::Color::Red);

    this->m_player_hp_bar_back=this->m_player_hp_bar;
    this->m_player_hp_bar_back.setFillColor(sf::Color(25,25,25,200));
}

void GuiManager::Update(int points, int health, int health_max)
{
    //Update Score
    std::stringstream ss;

    ss<<"Points:"<<points<<"\n"; 

    this->m_point_text.setString(ss.str());


    //Update Player GUI
    float hp_percent=static_cast<float>(health)/health_max;

    this->m_player_hp_bar.setSize(sf::Vector2f(
        300.f * hp_percent,
        this->m_player_hp_bar.getSize().y
    ));
}

void GuiManager::Render(sf::RenderTarget& target)
{
    target.draw(this->m_point_text);

    target.draw(this->m_player_hp_bar_back);
    target.draw(this->m_player_hp_bar); 

}
void GuiManager::GameOver(sf::RenderTarget& target)
{
    target.draw(this->m_game_over_text);
}

