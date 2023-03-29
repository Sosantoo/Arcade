/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** LibFileManager
*/

#pragma once
#include <string>
#include <vector>

namespace Lib
{
    enum libType{
        _GRAPHICALS_,
        _GAMES_,
    };

    struct lib {
        std::string name;
        std::string path;
        libType type;
    };
};

class LibFileManager {
    public:
        LibFileManager(const std::string &path);
        ~LibFileManager();
        Lib::lib ghraphicalCurrent;
        Lib::lib gameCurrent;

        void refreshAvailableLib();
        std::vector<Lib::lib> availableLib();
        bool isAvailable(const std::string &);
        void displayavailableLib();
        Lib::lib getLibByName(const std::string &name);
        Lib::lib getLibBypath(const std::string &name);

        Lib::lib getNextGraphicalsLib(const Lib::lib &loaded);
        Lib::lib getNextGameLib(const Lib::lib &loaded);

    private:
        Lib::libType getLibType(const std::string &);
        std::string _pathLib;
        std::vector<Lib::lib> _availableLibs;
};
