/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** DlfcnWrapper
*/

#include "arcade.hpp"

DlfcnWrapper::DlfcnWrapper()
{
}

DlfcnWrapper::DlfcnWrapper(const std::string &libName, int flags)
{
    this->open(libName, flags);
}

DlfcnWrapper::~DlfcnWrapper()
{
    if (_Handle)
        dlclose(_Handle);
}

void DlfcnWrapper::open(const std::string &libName, int flags ) {
    if (islibLoaded())
        close();
    _Handle = dlopen(libName.c_str(), flags);

    if (!islibLoaded())
        throw DlfcnExceptions::CannotOpenExceptions(dlerror());
}

void DlfcnWrapper::close() {
    dlclose(_Handle);
}

std::string DlfcnWrapper::error() {
    char *dl_error = dlerror();

    return (dl_error != nullptr) ? std::string{dl_error} : "";
}

void *DlfcnWrapper::sym(const std::string &symbol) {
    void *out;

    dlerror();
    out = dlsym(_Handle, symbol.c_str());

    std::string dlsym_error = error();
    if (!dlsym_error.empty())
        throw DlfcnExceptions::CannotLoadExceptions(dlsym_error);
    return out;
}

bool DlfcnWrapper::islibLoaded() {
    return _Handle != NULL;
}
