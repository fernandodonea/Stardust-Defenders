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
    this->point_text.setFont(font);
    this->point_text.setCharacterSize(36);
    this->point_text.setFillColor(sf::Color::White);
    this->point_text.setString("");
    this->point_text.setPosition(850.f,20.f);

}
void GuiManager::_InitGameOver(sf::Font &font,sf::RenderWindow* window)
{
    //Init GAME OVER text
    this->game_over_text.setFont(font);
    this->game_over_text.setCharacterSize(60);
    this->game_over_text.setFillColor(sf::Color::Red);
    this->game_over_text.setString("Game Over!");
    this->game_over_text.setPosition(
        window->getSize().x/2 - this->game_over_text.getGlobalBounds().width/2.f,
        window->getSize().y/2 - this->game_over_text.getGlobalBounds().height/2.f
    );
}
void GuiManager::_InitHealthBar()
{
    //Init player GUI
    this->player_hp_bar.setSize(sf::Vector2f(300.f,25.f));
    this->player_hp_bar.setPosition(sf::Vector2f(20.f,15.f));
    this->player_hp_bar.setFillColor(sf::Color::Red);

    this->player_hp_bar_back=this->player_hp_bar;
    this->player_hp_bar_back.setFillColor(sf::Color(25,25,25,200));
}

void GuiManager::Update(int points, int health, int health_max)
{
    //Update Score
    std::stringstream ss;

    ss<<"Points:"<<points<<"\n"; 

    this->point_text.setString(ss.str());


    //Update Player GUI
    float hp_percent=static_cast<float>(health)/health_max;

    this->player_hp_bar.setSize(sf::Vector2f(
        300.f * hp_percent,
        this->player_hp_bar.getSize().y
    ));
}

void GuiManager::Render(sf::RenderTarget& target)
{
    target.draw(this->point_text);

    target.draw(this->player_hp_bar_back);
    target.draw(this->player_hp_bar); 

}
void GuiManager::GameOver(sf::RenderTarget& target)
{
    target.draw(this->game_over_text);
}

