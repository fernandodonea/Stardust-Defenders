#ifndef PLAYER_MANAGER_H
#define PLAYER_MANAGER_H

#include "player.h"

class PlayerManager
{
    private:
        Player* m_player;
    public:
        //Constructors and destructors
        PlayerManager();
        ~PlayerManager();

        //Getter
        Player* GetPlayer();

        //Functions
        void WorldCollision(sf::RenderWindow *window);
        void Update(sf::RenderWindow *window);
};


#endif //PLAYER_MANAGER_H