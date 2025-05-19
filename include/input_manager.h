#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "player.h"
#include "bullet.h"

class InputManager
{
    private:
    public:

        void Movement(Player* player);
        void Attack(Player* player,std::vector<Bullet*>&bullets);

        void Update(Player* player,std::vector<Bullet*>&bullets);
};

#endif //INPUT_MANAGER_H