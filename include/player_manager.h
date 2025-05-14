#ifndef PLAYER_MANAGER_H
#define PLAYER_MANAGER_H

#include "player.h"

class PlayerManager
{
    private:
        Player* m_player;
        sf::RenderWindow *m_window;

        void _InitPlayer();
    public:
        //Constructors and destructors
        PlayerManager();
        PlayerManager(sf::RenderWindow *window);
        ~PlayerManager();

        //Getter
        Player* GetPlayer();

        //Functions
        void WorldCollision();
        void Update();
};


#endif //PLAYER_MANAGER_H