/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** libWrapper
*/

#ifndef LIBWRAPPER_HPP_
    #define LIBWRAPPER_HPP_
    #include "../various.hpp"

namespace Core
{
    class libWrapper {
        public:
            libWrapper(const std::string &path);
            ~libWrapper();

            std::map<std::string, std::string> refreshAvailableLib();
            std::map<std::string, std::string> availableLib();
            bool isAvailable(const std::string &);
            void displayavailableLib();

        private:
            std::string _pathLib;
            std::map<std::string, std::string> _availableLibs;
    };

}

#endif /* !LIBWRAPPER_HPP_ */
