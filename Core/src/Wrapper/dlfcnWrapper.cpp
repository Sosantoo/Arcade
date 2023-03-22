/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** DlfcnWrapper
*/

#include "arcade.hpp"

DlfcnWrapper::DlfcnWrapper()
    : _Handle(nullptr, dlclose)
{
}

DlfcnWrapper::DlfcnWrapper(const std::string& libName, int flags)
    : _Handle(nullptr, dlclose)
{
    open(libName, flags);
}

DlfcnWrapper::~DlfcnWrapper()
{
}

void DlfcnWrapper::open(const std::string &libName, int flags) {
   if (isLibLoaded())
        close();

    _Handle.reset(dlopen(libName.c_str(), flags));
    if (!isLibLoaded())
        throw DlfcnExceptions::CannotOpenExceptions(dlerror());
}

void DlfcnWrapper::close() {
    if (isLibLoaded()) {
        dlclose(_Handle.get());
        _Handle.release();
    }
}

std::string DlfcnWrapper::error() const {
    char *dl_error = dlerror();

    return (dl_error != nullptr) ? std::string{dl_error} : "";
}

void *DlfcnWrapper::sym(const std::string &symbol) {
    void *out;

    dlerror();
    out = dlsym(_Handle.get(), symbol.c_str());

    std::string dlsym_error = error();
    if (!out || !dlsym_error.empty())
        throw DlfcnExceptions::CannotLoadExceptions(dlsym_error);
    return out;
}

bool DlfcnWrapper::isLibLoaded() const {
    return _Handle.operator bool();
}
