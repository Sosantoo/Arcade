<p align="center">
  <a>
    <img alt="Arcade Logo" src="./arcade_logo.jpg"/>
  </a>
  <p align="center">A gaming platform.</p>
</p>

# Arcade

This project is ...

## Build

The CMakeLists.txt build the program. The project is composed with three graphics dynamic libraries and two game dynamic libraries at the root of the repository.
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

Enjoy the game !

## Documentation

The code is documented, using the Doxygen standard.
Wiki documentation is available.

## Authors
