/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** LibFileManager
*/

#include "lib/LibFileManager.hpp"
#include "Exceptions/CoreExceptions.hpp"
#include <filesystem>
#include <iostream>
#include <algorithm>
#include <map>

std::map<std::string, Lib::libType> libs_register {
    {"arcade_sdl2.so",      Lib::_GRAPHICALS_},
    {"arcade_ncurses.so",   Lib::_GRAPHICALS_},
    {"arcade_ndk++.so",     Lib::_GRAPHICALS_},
    {"arcade_aalib.so",     Lib::_GRAPHICALS_},
    {"arcade_libcaca.so",   Lib::_GRAPHICALS_},
    {"arcade_allegro5.so",  Lib::_GRAPHICALS_},
    {"arcade_xlib.so",      Lib::_GRAPHICALS_},
    {"arcade_gtk+.so",      Lib::_GRAPHICALS_},
    {"arcade_sfml.so",      Lib::_GRAPHICALS_},
    {"arcade_irrlicht.so",  Lib::_GRAPHICALS_},
    {"arcade_opengl.so",    Lib::_GRAPHICALS_},
    {"arcade_vulkan.so",    Lib::_GRAPHICALS_},
    {"arcade_qt5.so",       Lib::_GRAPHICALS_},
    {"arcade_snake.so",     Lib::_GAMES_},
    {"arcade_nibbler.so",   Lib::_GAMES_},
    {"arcade_pacman.so",    Lib::_GAMES_},
    {"arcade_qix.so",       Lib::_GAMES_},
    {"arcade_centipede.so", Lib::_GAMES_},
    {"arcade_solarfox.so",  Lib::_GAMES_},
    {"arcade_menu.so",      Lib::_MENU_},
};

LibFileManager::LibFileManager(const std::string &path):
    _pathLib{path}
{
    refreshAvailableLib();
}

LibFileManager::~LibFileManager()
{

}

Lib::libType LibFileManager::getLibType(const std::string &filename) {
    if (libs_register.count(filename) == 0)
        throw CoreExceptions::LibUnknowExceptions(filename);
    else
        return libs_register[filename];
}

void LibFileManager::refreshAvailableLib() {
    for (const auto& entry : std::filesystem::directory_iterator(_pathLib)) {
        if (!std::filesystem::is_regular_file(entry))
            continue;
        std::string name = std::filesystem::path(entry.path()).filename().string();
        _availableLibs.push_back({
            .name = name,
            .path = entry.path().string(),
            .type = getLibType(name),
        });
    }
}

std::vector<Lib::lib> LibFileManager::availableLib() {
    return _availableLibs;
}

bool LibFileManager::isAvailable(const std::string &path)
{
    auto iter = std::find_if(
        _availableLibs.begin(),
        _availableLibs.end(),
        [&path](const Lib::lib& m) -> bool { return m.path == path; }
    );
    return iter != _availableLibs.end();
}

void LibFileManager::displayavailableLib() {
    for (const auto &lib : _availableLibs)
        std::cout << lib.name << ": " << lib.path << std::endl;
}

Lib::lib LibFileManager::getLibByName(const std::string &name) {
    auto iter = std::find_if(
        _availableLibs.begin(),
        _availableLibs.end(),
        [&name](const Lib::lib& m) -> bool { return m.name == name; }
    );
    return (iter != _availableLibs.end()) ? *iter : Lib::lib();
}

Lib::lib LibFileManager::getLibBypath(const std::string &path) {
    auto iter = std::find_if(
        _availableLibs.begin(),
        _availableLibs.end(),
        [&path](const Lib::lib& m) -> bool { return m.path == path; }
    );
    return (iter != _availableLibs.end()) ? *iter : Lib::lib();
}

Lib::lib LibFileManager::getNextGraphicalsLib(const Lib::lib &loaded) {
    auto loadedIter = std::find(_availableLibs.begin(), _availableLibs.end(), loaded);
    auto iter = std::find_if(loadedIter + 1, _availableLibs.end(),
        [](const Lib::lib& m) -> bool { return m.type == Lib::_GRAPHICALS_; }
    );
    if (iter == _availableLibs.end()) {
        iter = std::find_if(_availableLibs.begin(), _availableLibs.end(),
            [](const Lib::lib& m) -> bool { return m.type == Lib::_GRAPHICALS_; }
        );
    }
    return iter != _availableLibs.end() ? *iter : Lib::lib{};
}

Lib::lib LibFileManager::getNextGameLib(const Lib::lib &loaded) {
    auto loadedIter = std::find(_availableLibs.begin(), _availableLibs.end(), loaded);
    auto iter = std::find_if(loadedIter + 1, _availableLibs.end(),
        [](const Lib::lib& m) -> bool { return m.type == Lib::_GAMES_; }
    );
    if (iter == _availableLibs.end()) {
        iter = std::find_if(_availableLibs.begin(), _availableLibs.end(),
            [](const Lib::lib& m) -> bool { return m.type == Lib::_GAMES_; }
        );
    }
    return iter != _availableLibs.end() ? *iter : Lib::lib{};
}
