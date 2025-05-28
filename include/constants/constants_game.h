#ifndef CONSTANTS_GAME_H
#define CONSTANTS_GAME_H
#include <string>

//Constants for Debugging
namespace Const_Debug
{
    const bool player_debug=false; 
    const bool enemy_debug=false;
    const bool projectile_debug=false;
}

//Constants for Window Settings
namespace Const_Window
{
    const int window_width=1024;
    const int window_height=728;
    const std::string window_title="Stardust Defenders";
}



#endif //CONSTANTS_GAME_H