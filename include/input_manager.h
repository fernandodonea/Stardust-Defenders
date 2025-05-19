/*
* @class InputManager
* @brief Handles player input and input-driven actions.

    InputManager is responsible for processing keyboard (and potentially other) input,
    translating it into player actions such as movement, shooting, and abilities.

*/


#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "player.h"
#include "bullet.h"

class InputManager
{
    private:
    public:
        //Functions
        void Movement(Player* player);
        void Attack(Player* player,std::vector<Bullet*>&bullets);

        void Update(Player* player,std::vector<Bullet*>&bullets);
};

#endif //INPUT_MANAGER_H