/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** libWrapper
*/

#include "arcade.hpp"
#include <filesystem>
#include <iostream>

std::map<std::string, Lib::lib_type> libs_register{
    {"arcade_sdl2.so", Lib::_GRAPHICALS_},
    {"arcade_ncurses.so", Lib::_GRAPHICALS_},
    {"arcade_ndk++.so", Lib::_GRAPHICALS_},
    {"arcade_aalib.so", Lib::_GRAPHICALS_},
    {"arcade_libcaca.so", Lib::_GRAPHICALS_},
    {"arcade_allegro5.so", Lib::_GRAPHICALS_},
    {"arcade_xlib.so", Lib::_GRAPHICALS_},
    {"arcade_gtk+.so", Lib::_GRAPHICALS_},
    {"arcade_sfml.so", Lib::_GRAPHICALS_},
    {"arcade_irrlicht.so", Lib::_GRAPHICALS_},
    {"arcade_opengl.so", Lib::_GRAPHICALS_},
    {"arcade_vulkan.so", Lib::_GRAPHICALS_},
    {"arcade_qt5.so", Lib::_GRAPHICALS_},
    {"arcade_snake.so", Lib::_GAMES_},
    {"arcade_nibbler.so", Lib::_GAMES_},
    {"arcade_pacman.so", Lib::_GAMES_},
    {"arcade_qix.so", Lib::_GAMES_},
    {"arcade_centipede.so", Lib::_GAMES_},
    {"arcade_solarfox.so", Lib::_GAMES_},
    {"arcade_menu.so", Lib::_GAMES_},
    {"testGame.so", Lib::_GAMES_},
};

libWrapper::libWrapper(const std::string &path) : _pathLib{path}
{
    refreshAvailableLib();
}

libWrapper::~libWrapper() {}

Lib::lib_type libWrapper::getLibType(const std::string &filename)
{
    if (libs_register.count(filename) == 0)
        throw CoreExceptions::LibUnknowExceptions(filename);
    return libs_register[filename];
}

void libWrapper::refreshAvailableLib()
{
    for (const auto &entry : std::filesystem::directory_iterator(_pathLib)) {
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

std::vector<Lib::lib_t> libWrapper::availableLib()
{
    return _availableLibs;
}

bool libWrapper::isAvailable(const std::string &path)
{
    auto iter = std::find_if(_availableLibs.begin(), _availableLibs.end(),
                             [&path](const Lib::lib_t &m) -> bool { return m.path == path; });
    return iter != _availableLibs.end();
}

void libWrapper::displayavailableLib()
{
    for (const auto &lib : _availableLibs)
        std::cout << lib.name << ": " << lib.path << std::endl;
}

Lib::lib_t libWrapper::getLibByName(const std::string &name)
{
    Lib::lib_t find;
    auto iter =
        std::find_if(_availableLibs.begin(), _availableLibs.end(),
                     [&name, &find](const Lib::lib_t &m) { return (find = m).name == name; });
    return (iter != _availableLibs.end()) ? find : Lib::lib_t();
}

Lib::lib_t libWrapper::getLibBypath(const std::string &path)
{
    auto iter = std::find_if(_availableLibs.begin(), _availableLibs.end(),
                             [&path](const Lib::lib_t &m) -> bool { return m.path == path; });
    return (iter != _availableLibs.end()) ? *iter : Lib::lib_t();
}

bool operator==(const Lib::lib_t &a, const Lib::lib_t &b)
{
    return a.name == b.name && a.path == b.path && a.type == b.type;
}

Lib::lib_t libWrapper::getNextGraphicalsLib(const Lib::lib_t &loaded)
{
    auto iter = std::find_if(_availableLibs.begin(), _availableLibs.end(),
                             [loaded](const Lib::lib_t &m) -> bool {
                                 return m.type == Lib::_GRAPHICALS_ && !(m == loaded);
                             });

    // If a library was found, return it and mark it as loaded
    return iter != _availableLibs.end() ? *iter : Lib::lib_t{};
}

Lib::lib_t libWrapper::getNextGameLib(const Lib::lib_t &loaded)
{
    auto iter = std::find_if(
        _availableLibs.begin(), _availableLibs.end(),
        [loaded](const Lib::lib_t &m) -> bool { return m.type == Lib::_GAMES_ && !(m == loaded); });
    return iter != _availableLibs.end() ? *iter : Lib::lib_t{};
}
