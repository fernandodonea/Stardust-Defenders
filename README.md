# OOP Project - Stardust Defenders

A classic-style space shooter game built with C++ and SFML to practice object-oriented programming (OOP). Take control of a spaceship and defend against waves of enemies while trying to achieve the highest score possible.


![Game Screenshot](/resources/screenshots/gameplay-normal.png)


**Check the [wiki](https://github.com/fernandodonea/Stardust-Defenders/wiki) for more details on the project structure and OOP principles used in this game.**

## Features

- **Player Controls**: Control your spaceship using `W`, `A`, `S`, `D` keys
- **GUI Elements**:
  - Score tracking
  - Health bar
  - Game over screen
- **Combat System**: 
  - Shoot bullets using the `spacebar`
  - Enemy collision detection
  - Combat scoring system
- **Enemy System**:
  - Continuous enemy spawning
  - Different enemy speed and health
  - Collision detection with player and bullets
- **Boss**:
  - Special alien boss enemy with laser attack 
  - Randomized movement

![Game Screenshot](/resources/screenshots/gameplay-boss.png)


# Installation Guide
 The following guide is for setting up the project on macOS and Linux devices. (UNIX-like systems). Support for windows in coming soon.


## Prerequisites
### macOS
- A Mac with Xcode installed (for Clang and C++17 support)
- [Homebrew](https://brew.sh/) for package management

### Linux
- A Linux distribution with a C++ compiler (GCC or Clang)

## Installing CMAKE
Open your terminal and run:
### macOs
```
brew install cmake
```
### Linux
```bash
sudo apt-get install cmake
```

## Installing SFML
Open your terminal and run:
### macOS
```bash
brew install sfml@2
```
**Note:** On Intel Macs, Homebrew typically installs packages in `/usr/local/Cellar`, while on Apple Silicon Macs the default prefix is `/opt/homebrew/Cellar`. 

To get the correct SFML path, you can run:

```bash
brew --prefix sfml@2
```

If neccessary, update the `CMakeLists.txt` file  to point to the correct SFML installation path.

### Linux
```bash
sudo apt update
sudo apt-get install libsfml-dev
```

## Building the Project

1. Clone this repository

```bash
git clone https://github.com/fernandodonea/Stardust-Defenders
cd Stardust-Defenders
```

2. Create a build directory and cofigure the project:
```bash
mkdir build
cd build
cmake ..
```

4. Build the project:
```bash
make
```

5. Navigate to the project root again:
```bash
cd ..
```

## How to Run the Game
To run the game, execute the following command in your terminal in the project root directory:
```bash
./StardustDefenders
```

