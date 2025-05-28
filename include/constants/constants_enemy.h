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

    const float sprite_margin=102.4f;

    const float alien_left_x   = sprite_margin/2 + 100.f;
    const float alien_center_x = 1024.f / 2.f - sprite_margin/2 ;
    const float alien_right_x  = 1024.f - sprite_margin - 100.f;
}

// Alien Positions





#endif // CONSTANTS_ASTEROID_H