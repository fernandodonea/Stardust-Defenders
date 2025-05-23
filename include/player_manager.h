/*
@class PlayerManager
@brief Manages the player entity and its interactions.

    PlayerManager is responsible for creating, updating, and managing the player object.

    It handles world collision, attack cooldowns, and provides access to the player for other systems.

*/


#ifndef PLAYER_MANAGER_H
#define PLAYER_MANAGER_H

#include "player.h"

class PlayerManager
{
    private:
        Player* m_player;
    
    public:
        //Constructor and destructor
        PlayerManager(sf::Texture* texture);
        ~PlayerManager();

        //Getter
        Player* GetPlayer();

        //Functions
        void WorldCollision(sf::RenderWindow *window);
        void Update(sf::RenderWindow *window);
};


#endif //PLAYER_MANAGER_H