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
class LibHandler {
    private:
        using create_interface_t = std::unique_ptr<Interface_t> (*)();

        std::unique_ptr<Interface_t> _interface;
        std::unique_ptr<Interface_t> _previousInterface;
        create_interface_t _constructor;
        SharedLibLoader sharedLibLoader;

    public:
        LibHandler();
        LibHandler(const Lib::lib &, const Lib::libType);
        ~LibHandler();

        void load(const Lib::lib &, const Lib::libType);
        Interface_t& getInterface();
};
