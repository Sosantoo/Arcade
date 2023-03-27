/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** libWrapper
*/

#ifndef LIBWRAPPER_HPP_
    #define LIBWRAPPER_HPP_
    #include "../various.hpp"

namespace Lib
{
    enum lib_type{
        _GRAPHICALS_,
        _GAMES_,
    };

    struct lib_t {
        std::string name;
        std::string path;
        lib_type type;
    };
};

class libWrapper {
    public:
        libWrapper(const std::string &path);
        ~libWrapper();

        void refreshAvailableLib();
        std::vector<Lib::lib_t> availableLib();
        bool isAvailable(const std::string &);
        void displayavailableLib();
        Lib::lib_t getLibByName(const std::string &name);
        Lib::lib_t getLibBypath(const std::string &name);

        Lib::lib_t getNextGraphicalsLib(const Lib::lib_t &loaded);
        Lib::lib_t getNextGameLib(const Lib::lib_t &loaded);

    private:
        Lib::lib_type getLibType(const std::string &);

        std::string _pathLib;
        std::vector<Lib::lib_t> _availableLibs;
};

#endif /* !LIBWRAPPER_HPP_ */
