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
InterfaceWrapper<Interface_t>::InterfaceWrapper(const std::string& libPath, int flags)
    : DlfcnWrapper(libPath, flags)
{
    load(libPath);
}

template <typename Interface_t>
InterfaceWrapper<Interface_t>::~InterfaceWrapper()
{
    if (_interface)
        _destructorGraphical(_interface.get());
}

template <typename Interface_t>
void InterfaceWrapper<Interface_t>::load(const std::string& libPath) {
    open(libPath, 1);
    _constructorGraphical = (create_interface_t*)sym("create");
    _destructorGraphical = (destroy_interface_t*)sym("destroy");
    _interface.reset(_constructorGraphical());
}

template <typename Interface_t>
Interface_t * InterfaceWrapper<Interface_t>::getInterface() {
        return _interface.get();
}

template class InterfaceWrapper<IGame>;
template class InterfaceWrapper<IGraphical>;
