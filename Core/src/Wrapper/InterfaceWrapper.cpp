/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** InterfaceWrapper
*/

#include "arcade.hpp"

template <typename Interface_t>
InterfaceWrapper<Interface_t>::InterfaceWrapper()
{
}

template <typename Interface_t>
InterfaceWrapper<Interface_t>::InterfaceWrapper(const Lib::lib_t &lib, const Lib::lib_type expected_type)
    : DlfcnWrapper(lib.path)
{
    load(lib, expected_type);
}

template <typename Interface_t>
InterfaceWrapper<Interface_t>::~InterfaceWrapper()
{
}

template <typename Interface_t>
void InterfaceWrapper<Interface_t>::load(const Lib::lib_t &lib, const Lib::lib_type expected_type) {
    if (lib.type != expected_type)
        throw DlfcnExceptions::CannotOpenExceptions("wrong lib type: " + lib.name);
    _interface.reset();
    open(lib.path);
    _constructor = (create_interface_t)sym("create");
    _interface.reset(_constructor());
    if (_interface == nullptr)
        throw DlfcnExceptions::CannotOpenExceptions("failed loading lib");
}

template <typename Interface_t>
std::shared_ptr<Interface_t>& InterfaceWrapper<Interface_t>::getInterface() {
    return _interface;
}

template class InterfaceWrapper<IGame>;
template class InterfaceWrapper<IGraphical>;
