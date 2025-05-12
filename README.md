# OOP Project - Stardut Defenders

A classic-style space shooter game built with C++ and SFML to practice object-oriented programming (OOP). Take control of a spaceship and defend against waves of enemies while trying to achieve the highest score possible.

![Game Screenshot](/resources/screenshots/gameplay.png)

## Class hierarchy
```
Entity (Abstract Base Class)
├── Player
├── Projectile (Abstract)
│   ├── PlayerBullet
│   └── BossBullet
└── Enemy (Abstract)
    ├── BasicEnemy
    ├── FastEnemy
    ├── TankEnemy
    └── Boss
```


## Features

- **Player Controls**: Control your spaceship using `W`,`A`,`S`,`D` keys
- **Combat System**: 
  - Shoot bullets using the `spacebar`
  - Enemy collision detection
  - Combat scoring system
- **Enemy System**:
  - Continuous enemy spawning
  - Different enemy speed and health
  - Collision detection with player and bullets
- **GUI Elements**:
  - Score tracking

## Controls

- **W** - Move Up
- **S** - Move Down
- **A** - Move Left
- **D** - Move Right
- **Space** - Shoot
- **ESC** - Exit Game



