# Ludo Game 🎲

A classic Ludo board game implementation using C++ and SFML, featuring multiplayer support, graphical elements, and sound effects.

## Table of Contents
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Building](#building)
- [Running](#running)
- [Gameplay](#gameplay)
- [Project Structure](#project-structure)
- [Code Overview](#code-overview)
- [License](#license)

## Features ✨
- 2-6 player support
- SFML-based graphical interface
- Dice roll animations
- Sound effects and background music
- Color-coded player pieces
- Interactive game board

## Prerequisites 📦
- [SFML 2.5.x](https://www.sfml-dev.org/download.php)
- C++17 compatible compiler (GCC, MSVC, Clang)
- [CMake](https://cmake.org/download/) (recommended)

## Installation ⚙️

### Linux
```bash
# Install SFML dependencies
sudo apt-get install libsfml-dev
```

### Windows
1. Download [SFML binaries](https://www.sfml-dev.org/download/sfml/2.5.1/)
2. Add SFML include directory to your IDE's include paths
3. Link SFML libraries (graphics, window, system, audio)

## Building 🛠️

### Using CMake (Recommended)
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Manual Compilation
```bash
g++ -std=c++17 -I./include -I/path/to/sfml/include *.cpp -o Ludo \
-L/path/to/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```

## Running 🚀
```bash
# Linux
./Ludo

# Windows
Ludo.exe
```

## Gameplay 🎮
1. Launch the executable
2. Select number of players (2-6)
3. Click the dice to roll
4. Move pieces according to dice value
5. Reach the center to win!

**Controls:**
- Left click: Select pieces
- Spacebar: Roll dice
- ESC: Exit game

## Project Structure 📂
```
├── CMakeLists.txt          # Build configuration
├── src/
│   ├── Main.cpp            # Entry point
│   ├── Game/               # Core game logic
│   ├── Board/              # Board rendering
│   ├── Pieces/             # Player piece implementations
│   └── Players/            # Player management
├── assets/
│   ├── audio/              # Sound effects and music
│   ├── fonts/              # Font files
│   └── textures/           # Game sprites and images
└── external/               # SFML dependencies (if included)
```

## Code Overview 📚
| Component         | Description                                  |
|-------------------|----------------------------------------------|
| `Game.cpp`        | Main game loop and state management          |
| `Board.cpp`       | Board rendering and collision detection      |
| `Piece.cpp`       | Piece movement and animation logic           |
| `Player.cpp`      | Player turns and piece management            |
| `Dice.cpp`        | Dice rolling mechanics                       |
| `SoundManager.cpp`| Audio playback and resource management       |

## License 📄
This project is licensed under the MIT License - see [LICENSE](LICENSE) file for details.



