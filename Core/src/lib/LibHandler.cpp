/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** LibHandler
*/

#include "lib/LibHandler.hpp"
#include "lib/SharedLibLoader.hpp"
#include "lib/LibFileManager.hpp"
#include "interface.hpp"
#include "Exceptions/DlfcnExceptions.hpp"

template <typename Interface_t>
LibHandler<Interface_t>::LibHandler()
{
}

template <typename Interface_t>
LibHandler<Interface_t>::LibHandler(const Lib::lib &lib, const Lib::libType expected_type)
    : SharedLibLoader(lib.path)
{
    load(lib, expected_type);
}

template <typename Interface_t>
LibHandler<Interface_t>::~LibHandler()
{
}

template <typename Interface_t>
void LibHandler<Interface_t>::load(const Lib::lib &lib, const Lib::libType expected_type) {
    if (lib.type != expected_type)
        throw DlfcnExceptions::CannotOpenExceptions("wrong lib type: " + lib.name);
    open(lib.path);

    _constructor = (create_interface_t)sym("create");
    _interface = _constructor();

    if (_interface == nullptr)
        throw DlfcnExceptions::CannotOpenExceptions("failed loading lib");
}

template <typename Interface_t>
Interface_t& LibHandler<Interface_t>::getInterface() {
    return *_interface;
}

template <typename Interface_t>
std::unique_ptr<Interface_t> LibHandler<Interface_t>::getInterfacePtr() {
    return std::move(_interface);
}

template class LibHandler<IGame>;
template class LibHandler<IGraphicalFactory>;
