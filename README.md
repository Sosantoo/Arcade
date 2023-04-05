<p align="center">
  <a>
    <img alt="Arcade Logo" src="./assets/arcade.webp"/>
  </a>
  <p align="center">A gaming platform.</p>
</p>

# Arcade

Arcade is a gaming platform, a program that lets the user choose a game to play and keeps a register of player scores.

## Subject

[![sub](https://img.shields.io/badge/Subject-pdf-red.svg)](./assets/B-OOP-400_arcade.pdf)

## Build

`Requirements`

- C++20 COMPILER
- cmake VERSION 3.5.1

`Libraries`

- SFML
- SDL2
- SDL2_TTF
- NCURSES

`CMake`

Simple guide to setup the project via CMake as follows:

```
$ mkdir ./build/ && cd ./build/
$ cmake .. -G “Unix Makefiles” -DCMAKE_BUILD_TYPE=Release
[. . .]
$ cmake --build .
[. . .]
$ cd ..
$ ls ./arcade ./lib/
./arcade

./lib/:
arcade_ncurses.so
arcade_pacman.so
arcade_sdl2.so
arcade_sfml.so
arcade_solarfox.so
[. . .]
```

## Documentation

This project is documented with Doxygen, which is the de facto standard tool for generating documentation from annotated C++ sources. <br>
There is also a ./doc directory, explaining how to implement new graphics libraries or game libraries compatible with
the system.

## Librairies

`Graphicals libraries`

The nCurses, SDL2 and SFML graphical libraries have been implemented.

```
• nCurses (arcade_ncurses.so)
• SDL2 (arcade_sdl2.so)
• SFML (arcade_sfml.so)
```

`Game libraries`

The Snake and Nibbler game libraries have been implemented.

```
• Snake (arcade_snake.so)
• Nibbler (arcade_nibbler.so)
```

## Usage

```
USAGE:
  ./arcade path_to_graphical_lib

DESCRIPTION:
  /lib folder         path to the initial graphical library to load (./lib/arcade_lib_name.so)

COMMANDS (azerty layout):
  Y                         Next graphics lib.
  U                         Next game.
  I                         Restart the game.
  O                         Go back to the menu.
  P                         Exit.

  D | Right Arrow           Move right.
  Q | Left Arrow            Move left.
  Z | Up Arrow              Move up.
  S | Down Arrow            Move down.
  
  Left | Right Arrow        Menu navigation, choose graphicals libraries.
  Up | Down Arrow           Menu navigation, choose game libraries.      
```

## Documentation

[![doc](https://img.shields.io/badge/Documentation-html-red.svg)](./doc/html)
[![doc](https://img.shields.io/badge/Documentation-pdf-red.svg)](./doc/arcade_doc.pdf)

## Contributors

- [Raphael Camblong](https://github.com/raphaelCamblong)
- [Leopold Sallan Gemard](https://github.com/sosantoo/)
- [Pierre Bouillard](https://github.com/pierrrebouillard)
