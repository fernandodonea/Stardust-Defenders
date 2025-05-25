#ifndef CONSTANTS_ASTEROID_H
#define CONSTANTS_ASTEROID_H

// Constants for Asteroid and Alien 

namespace Const_Asteroid_Normal
{
    const float movement_speed=4.f;
    const int hp=20;
    const int hp_max=20;
    const int damage=10;
    const int points=25;
    const float size=0.3;
}
namespace Const_Asteroid_Fast
{
    const float movement_speed=6.f;
    const int hp=10;
    const int hp_max=10;
    const int damage=15;
    const int points=50;
    const float size=0.2;
}
namespace Const_Asteroid_Tank
{
    const float movement_speed=2.f;
    const int hp=40;
    const int hp_max=40;
    const int damage=30;
    const int points=100;
    const float size=0.5;
}

namespace Const_Alien
{
    const float movement_speed=6.f;
    const int hp=200;
    const int hp_max=200;
    const int damage=35;
    const int points=1000;
    const float size=0.4;
}

// Alien Positions

const float WINDOW_WIDTH = 1024.f;
const float SPRITE_MARGIN = 102.4f;

const float ALIEN_LEFT_X   = SPRITE_MARGIN/2 + 100.f;
const float ALIEN_CENTER_X = WINDOW_WIDTH / 2.f - SPRITE_MARGIN/2 ;
const float ALIEN_RIGHT_X  = WINDOW_WIDTH - SPRITE_MARGIN - 100.f;




#endif // CONSTANTS_ASTEROID_H