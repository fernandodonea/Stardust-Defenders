# OOP Project - Stardut Defenders

A classic-style space shooter game built with C++ and SFML to practice object-oriented programming (OOP). Take control of a spaceship and defend against waves of enemies while trying to achieve the highest score possible.

![Game Screenshot](/resources/screenshots/gameplay.png)

## Class hierarchy
```
Entity (Abstract Base Class)
├── Player
├── Projectile (Abstract)
│   ├── PlayerBullet
│   └── BossBullet //TODO
└── Enemy (Abstract)
    ├── BasicEnemy
    ├── FastEnemy
    ├── TankEnemy
    └── Boss //TODO
```
```
Manager Classes
├── WindowManager
├── ResourceManager
├── GuiManager
├── PlayerManager
├── EnemyManager
├── BulletManager
├── CombatManager
├── InputManager
└── WorldManager

```

## Manager Classes

- **WindowManager**: Manages the game window and window-related events.

- **ResourceManager**: Loads, stores, and provides access to textures and fonts.

- **GuiManager**: Handles all GUI elements (score, health bar, game over screen).

- **PlayerManager**: Manages the player entity, movement, and world collision.

- **EnemyManager**: Spawns, updates, and removes enemies.

- **BulletManager**: Creates, updates, and deletes bullets.

- **CombatManager**: Handles all combat logic (player-enemy and bullet-enemy collisions).

- **InputManager**: Processes player input for movement, shooting.

- **WorldManager**: Manages the world background and global game variables (score, etc.).


## Features

- **Player Controls**: Control your spaceship using `W`, `A`, `S`, `D` keys
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
  - Health bar
  - Game over screen

## Controls

- **W** - Move Up
- **S** - Move Down
- **A** - Move Left
- **D** - Move Right
- **Space** - Shoot
- **ESC** - Exit Game



