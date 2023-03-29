/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SharedLibLoader
*/

#include "lib/SharedLibLoader.hpp"
#include "Exceptions/DlfcnExceptions.hpp"

SharedLibLoader::SharedLibLoader()
    : _Handle(nullptr, dlclose)
{
}

SharedLibLoader::SharedLibLoader(const std::string& libName, int flags)
    : _Handle(nullptr, dlclose)
{
    this->open(libName, flags);
}

SharedLibLoader::~SharedLibLoader()
{
}

void SharedLibLoader::open(const std::string &libName, int flags) {
   if (isLibLoaded())
        this->close();

    _Handle.reset(dlopen(libName.c_str(), flags));
    if (!isLibLoaded())
        throw DlfcnExceptions::CannotOpenExceptions(dlerror());
}

void SharedLibLoader::close() {
    _Handle.reset();
}

std::string SharedLibLoader::error() const {
    char *dl_error = dlerror();

    return (dl_error != nullptr) ? std::string{dl_error} : "";
}

void *SharedLibLoader::sym(const std::string &symbol) {
    void *out;

    dlerror();
    out = dlsym(_Handle.get(), symbol.c_str());

    std::string dlsym_error = error();
    if (!out || !dlsym_error.empty())
        throw DlfcnExceptions::CannotLoadExceptions(dlsym_error);
    return out;
}

bool SharedLibLoader::isLibLoaded() const {
    return _Handle.operator bool();
}
