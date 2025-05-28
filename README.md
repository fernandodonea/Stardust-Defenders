# OOP Project - Stardust Defenders

A classic-style space shooter game built with C++ and SFML to practice object-oriented programming (OOP). Take control of a spaceship and defend against waves of enemies while trying to achieve the highest score possible.

![Game Screenshot](/resources/screenshots/gameplay.png)


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

## Installation


### Prerequisites
- A Mac with Xcode installed (for Clang and C++17 support)
- [Homebrew](https://brew.sh/) for package management
- SFML v2 (installed via Homebrew)

### Installing SFML
Open your terminal and run:
```bash
brew install sfml@2
```
**Note:** On Intel Macs, Homebrew typically installs packages in `/usr/local/Cellar`, while on Apple Silicon Macs the default prefix is `/opt/homebrew/Cellar`. 

To get the correct SFML path, you can run:

```bash
brew --prefix sfml@2
```

If neccessary, update the `CMakeLists.txt` file  to point to the correct SFML installation path.

### Building the Project

1. Clone this repository

```bash
git clone https://github.com/fernandodonea/Stardust-Defenders
```

2. Navigate to the project root:
```bash
cd Stardust-Defenders
```

3. Create a build directory and navigate into it:
```bash
mkdir build && cd build
```

4. Configure the project with CMake:
  ```bash
  cmake ..
  ```

5. Build the project:
```bash
cmake --build .
```

6. Navigate to the project root again:
```bash
cd ..
```

### How to Run the Game
To run the game, execute the following command in your terminal in the project root directory:
```bash
./StardustDefenders
```
