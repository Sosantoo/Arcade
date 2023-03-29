/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** InterfaceWrapper
*/

#pragma once
#include "Wrapper/libWrapper.hpp"
#include "dlfcnWrapper.hpp"

template <typename Interface_t> class InterfaceWrapper : public DlfcnWrapper
{
    public:
        using create_interface_t = Interface_t *(*)();

        InterfaceWrapper();
        InterfaceWrapper(const Lib::lib_t &, const Lib::lib_type);
        ~InterfaceWrapper();

        void load(const Lib::lib_t &, const Lib::lib_type);

        std::shared_ptr<Interface_t> &getInterface();

    private:
        std::shared_ptr<Interface_t> _interface;
        create_interface_t _constructor;
};
