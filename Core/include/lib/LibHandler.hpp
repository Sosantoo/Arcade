/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** LibHandler
*/

#pragma once
#include <memory>
#include "lib/SharedLibLoader.hpp"
#include "lib/LibFileManager.hpp"

template <typename Interface_t>
class LibHandler: public SharedLibLoader {
    public:
        using create_interface_t = std::unique_ptr<Interface_t> (*)();

        LibHandler();
        LibHandler(const Lib::lib &, const Lib::libType);
        ~LibHandler();

        void load(const Lib::lib &, const Lib::libType);

        Interface_t& getInterface();

        std::unique_ptr<Interface_t> getInterfacePtr();

    private:
        std::unique_ptr<Interface_t> _interface;
        create_interface_t _constructor;
};
