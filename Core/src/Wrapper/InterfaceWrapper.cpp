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
InterfaceWrapper<Interface_t>::InterfaceWrapper(const Lib::lib_t &lib)
    : DlfcnWrapper(lib.path)
{
    load(lib);
}

template <typename Interface_t>
InterfaceWrapper<Interface_t>::~InterfaceWrapper()
{
    if (_interface)
        _destructor(_interface.get());
}

template <typename Interface_t>
void InterfaceWrapper<Interface_t>::load(const Lib::lib_t &lib) {
    open(lib.path);

    _constructor = (create_interface_t*)sym("create");
    _destructor = (destroy_interface_t*)sym("destroy");

    _interface.reset(_constructor());
}

template <typename Interface_t>
Interface_t * InterfaceWrapper<Interface_t>::getInterface() {
        return _interface.get();
}

template class InterfaceWrapper<IGame>;
template class InterfaceWrapper<IGraphical>;
