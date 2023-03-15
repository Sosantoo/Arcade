/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** libWrapper
*/

#include "arcade.hpp"
#include <filesystem>

Core::libWrapper::libWrapper(const std::string &path):
    _pathLib{path}
{
    refreshAvailableLib();
}

Core::libWrapper::~libWrapper()
{

}

std::map<std::string, std::string> Core::libWrapper::refreshAvailableLib() {
    for (const auto& entry : std::filesystem::directory_iterator(_pathLib)) {
        if (!std::filesystem::is_regular_file(entry))
            continue;
        std::string filename = std::filesystem::path(entry.path()).filename().string();
        _availableLibs[std::string(entry.path().string())] = std::string(filename);
    }
    return _availableLibs;
}

std::map<std::string, std::string> Core::libWrapper::availableLib() {
    return _availableLibs;
}

bool Core::libWrapper::isAvailable(const std::string &path)
{
    return _availableLibs.count(path) >= 1;
}

void Core::libWrapper::displayavailableLib() {
    for (const auto &lib : _availableLibs)
        std::cout << lib.first << ": " << lib.second << std::endl;
}
