#include "../include/player_manager.h"

void PlayerManager::_InitPlayer()
{
    this->m_player=new Player();
}

//Constructors and destructors
PlayerManager::PlayerManager()
{
   
}
PlayerManager::PlayerManager(sf::RenderWindow *window)
{
    this->m_window=window;
    _InitPlayer();
}
PlayerManager::~PlayerManager()
{
    delete this->m_player;
}

//Getter
Player* PlayerManager::GetPlayer()
{
    return this->m_player;
} 

//Functions
void PlayerManager::WorldCollision()
{
    //Left world collision
    if(this->m_player->GetBounds().left<0.f)
    {
        this->m_player->SetPosition(
            0.f,
            this->m_player->GetBounds().top
        );
    }
    //Right world collision
    else if(this->m_player->GetBounds().left+this->m_player->GetBounds().width > this->m_window->getSize().x)
    {
        this->m_player->SetPosition(
            this->m_window->getSize().x - this->m_player->GetBounds().width,
            this->m_player->GetBounds().top
        );
    }
    //Top world collision
    if(this->m_player->GetBounds().top<0.f)
    {
        this->m_player->SetPosition(
            this->m_player->GetBounds().left,
            0.f
        );
    }
    //Bottom world collision
    else if(this->m_player->GetBounds().top+this->m_player->GetBounds().height > this->m_window->getSize().y)
    {
        this->m_player->SetPosition(
            this->m_player->GetBounds().left,
            this->m_window->getSize().y - this->m_player->GetBounds().height
        );
    }

}
void PlayerManager::Update()
{
    WorldCollision();
    GetPlayer()->UpdateAttack();
}