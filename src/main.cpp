#include "game.h"
#include <time.h>


int main()
{
    srand(static_cast<unsigned int>(time(0))); 


    Game_Engine::Game game;

    game.Run();


    // Your code here
    return 0;
} 