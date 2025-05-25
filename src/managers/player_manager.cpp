#include "../include/managers/player_manager.h"


/*
-------------------------------
    Constructor and destructor
-------------------------------
*/

PlayerManager::PlayerManager(sf::Texture* texture)
{
    this->m_player=new Player(texture);
}

PlayerManager::~PlayerManager()
{
    delete this->m_player;
}


/*
------------
    Getter
------------
*/

Player* PlayerManager::GetPlayer()
{
    return this->m_player;
} 


/*
---------------
    Functions
---------------
*/
void PlayerManager::WorldCollision(sf::RenderWindow *window)
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
    else if(this->m_player->GetBounds().left+this->m_player->GetBounds().width > window->getSize().x)
    {
        this->m_player->SetPosition(
            window->getSize().x - this->m_player->GetBounds().width,
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
    else if(this->m_player->GetBounds().top+this->m_player->GetBounds().height > window->getSize().y)
    {
        this->m_player->SetPosition(
            this->m_player->GetBounds().left,
            window->getSize().y - this->m_player->GetBounds().height
        );
    }
}

void PlayerManager::Update(sf::RenderWindow *window)
{
    WorldCollision(window);

    GetPlayer()->UpdateAttack();
}