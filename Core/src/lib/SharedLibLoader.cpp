/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SharedLibLoader
*/

#include "lib/SharedLibLoader.hpp"
#include "Exceptions/DlfcnExceptions.hpp"
#include <memory>
#include <dlfcn.h>
#include <string>

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
    (void)flags;
    if (_Handles.size() >= 2) _Handles.erase(_Handles.begin());

    void *handle = dlopen(libName.c_str(), RTLD_NOW);

    if (!handle)
        throw DlfcnExceptions::CannotOpenExceptions(dlerror());
    _Handles.emplace_back(handle, dlclose);
}

void SharedLibLoader::close() {
    _Handles.clear();
}

std::string SharedLibLoader::error() const {
    char *dl_error = dlerror();

    return (dl_error != nullptr) ? std::string{dl_error} : "";
}

void *SharedLibLoader::sym(const std::string &symbol) {
    void *out;

    dlerror();
    out = dlsym(_Handles.back().get(), symbol.c_str());

    std::string dlsym_error = error();
    if (!out || !dlsym_error.empty())
        throw DlfcnExceptions::CannotLoadExceptions(dlsym_error);
    return out;
}

bool SharedLibLoader::isLibLoaded() const {
    return _Handles.back().operator bool();
}
