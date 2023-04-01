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
    : _interface{nullptr}
    , _previousInterface{nullptr}
{
}

template <typename Interface_t>
LibHandler<Interface_t>::LibHandler(const Lib::lib &lib, const Lib::libType expected_type)
    : _interface{nullptr}
    , _previousInterface{nullptr}
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

    _previousInterface = std::move(_interface);

    sharedLibLoader.open(lib.path);
    _constructor = reinterpret_cast<create_interface_t>(sharedLibLoader.sym("create"));
    _interface = _constructor ? _constructor() : nullptr;

    if (!_interface)
        throw DlfcnExceptions::CannotOpenExceptions("failed loading lib");
}

template <typename Interface_t>
Interface_t& LibHandler<Interface_t>::getInterface() {
    return *_interface;
}

template class LibHandler<IGame>;
template class LibHandler<IGraphicalFactory>;
