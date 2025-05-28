/*

PlayerManager manages the player entity and its interactions.

Responsible for creating, updating, and managing the player object, 
handling world collision, and attack cooldowns.

*/


#ifndef PLAYER_MANAGER_H
#define PLAYER_MANAGER_H

#include "../entities/player.h"

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